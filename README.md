# push_swap

A C program that emits instructions to sort integers using two stacks and a restricted set of operations.

Built as a 42 curriculum project to practice linked lists, input validation, and algorithm design under operational constraints.

## Build and use

Requires a C compiler and Make.

```bash
git clone https://github.com/ahmedaitelaaoud/push_swap.git
cd push_swap
make
./push_swap 3 2 1
```

The program prints operations, not the sorted integers. For this example it emits:

```text
ra
sa
```

Already sorted input emits nothing. Invalid input, including duplicate integers, is rejected with `Error` on standard error.

## Algorithm

1. Parse integers and assign ranks from smallest to largest.
2. Use dedicated handling for stacks of two through five elements.
3. For larger inputs, move ranks into stack B using a moving window: 15 ranks below 500 elements, 33 at 500 or more.
4. Repeatedly move the largest remaining rank to the top of B using the shorter rotation direction, then push it back to A.

The window is a heuristic, not a proof of the fewest possible operations. Repeated linked-list scans also contribute to runtime; operation count and execution time are different measurements.

## Code map

| Files | Responsibility |
| --- | --- |
| `check_args.c`, `pars_init.c`, `ft_split.c` | Parsing and validation |
| `stack_init.c`, `stack_utils.c` | Stack construction, ranking, and helpers |
| `swap.c`, `push.c`, `rotate.c`, `rev_rotate.c` | Stack operations |
| `sort_tiny.c`, `sort_big.c` | Small-input routines and window-based sorting |
| `main.c` | Size-based dispatch and cleanup |

The instruction vocabulary is `sa sb ss pa pb ra rb rr rra rrb rrr`: swaps, pushes, rotations, and reverse rotations on A, B, or both.

## Tests

Python 3 is needed only for the test runner.

```bash
make
python3 -m unittest discover -s tests -p 'test_*.py'
```

The tests run the real executable, replay its operations, and verify that A is sorted and B is empty. Coverage includes every permutation of sizes 1–5, deterministic samples of sizes 6, 20, 100, and 500, already sorted input, and duplicate rejection.

A regression test covers descending two-element input, which previously fell through the dispatcher without producing an operation.

## Limitations and next steps

The test suite is not a memory-safety audit or a benchmark. Add allocation-failure and integer-boundary cases, run Valgrind or sanitizers, and publish operation-count measurements only with a reproducible generator and checker.

```bash
make clean
make fclean
```

## License

No repository-level license is currently included.

