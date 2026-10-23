"""Black-box checks: replay emitted operations and inspect the resulting stacks."""
import itertools
from pathlib import Path
import random
import subprocess
import unittest

BIN = Path(__file__).resolve().parents[1] / "push_swap"


def replay(values, operations):
    a, b = list(values), []
    for op in operations:
        if op in ("sa", "sb", "ss"):
            for stack in ([a] if op == "sa" else [b] if op == "sb" else [a, b]):
                if len(stack) > 1:
                    stack[0], stack[1] = stack[1], stack[0]
        elif op in ("pa", "pb"):
            dest, source = (a, b) if op == "pa" else (b, a)
            if source:
                dest.insert(0, source.pop(0))
        elif op in ("ra", "rb", "rr", "rra", "rrb", "rrr"):
            stacks = [a] if op in ("ra", "rra") else [b] if op in ("rb", "rrb") else [a, b]
            for stack in stacks:
                if stack:
                    if op in ("rra", "rrb", "rrr"):
                        stack.insert(0, stack.pop())
                    else:
                        stack.append(stack.pop(0))
        else:
            raise AssertionError(f"Unknown operation: {op}")
    return a, b


class SortingCLI(unittest.TestCase):
    def assert_sorted(self, values):
        result = subprocess.run([str(BIN), *map(str, values)], capture_output=True, text=True, timeout=5)
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(replay(values, result.stdout.splitlines()), (sorted(values), []))

    def test_descending_pair(self):
        self.assert_sorted([2, 1])

    def test_small_permutations(self):
        for size in range(1, 6):
            for values in itertools.permutations(range(size)):
                with self.subTest(values=values):
                    self.assert_sorted(values)

    def test_larger_inputs(self):
        rng = random.Random(42)
        for size in (6, 20, 100, 500):
            self.assert_sorted(rng.sample(range(-10000, 10000), size))

    def test_sorted_input_emits_nothing(self):
        result = subprocess.run([str(BIN), "1", "2"], capture_output=True, text=True, timeout=5)
        self.assertEqual(result.returncode, 0)
        self.assertEqual(result.stdout, "")

    def test_duplicate_rejected(self):
        result = subprocess.run([str(BIN), "1", "1"], capture_output=True, text=True, timeout=5)
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(result.stderr, "Error\n")


if __name__ == "__main__":
    unittest.main()
