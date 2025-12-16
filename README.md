# 42 Push_swap

## 💡 Overview
**Push_swap** is a 42 School algorithm project. The task is simple: You have a stack of random integers (Stack A) and an empty stack (Stack B). You must sort Stack A in ascending order using a strict set of operations and the smallest number of moves possible.

This project focuses on **complexity analysis**, **sorting algorithms**, and **data structure manipulation**.

---

## 🏗️ Data Structures

### Why Linked Lists?
Standard arrays are inefficient for this project because `push` and `rotation` operations require shifting elements constantly. To achieve efficient modifications, we use a **Doubly Linked List**.

- **Stack Behavior:** We treat the beginning of the list as the "Top" and the end as the "Bottom".
- **Double Links:** We need pointers to both `next` and `prev` nodes to perform `rra` (Reverse Rotate) efficiently without traversing the whole list every time.

### The Node
Each element (node) in the stack contains:

| Field | Type | Description |
| :--- | :--- | :--- |
| `value` | `int` | The actual integer provided in the arguments. |
| `index` | `int` | The normalized rank of the number (0 to size-1). |
| `next` | `*ptr` | Pointer to the element below. |
| `prev` | `*ptr` | Pointer to the element above. |

---

## 🛠️ The Instruction Set

The only allowed moves to manipulate the stacks are:

### Swap (Cost: Low)
Corrects the order of the top two elements.
- `sa` : Swap the first 2 elements at the top of stack A.
- `sb` : Swap the first 2 elements at the top of stack B.
- `ss` : `sa` and `sb` at the same time.

### Push (Cost: Essential)
Moves elements between stacks.
- `pa` : Take the first element at the top of B and put it at the top of A.
- `pb` : Take the first element at the top of A and put it at the top of B.

### Rotate (Cost: Navigation)
Shifts elements up. The first element becomes the last.
- `ra` : Shift up all elements of stack A by 1.
- `rb` : Shift up all elements of stack B by 1.
- `rr` : `ra` and `rb` at the same time.

### Reverse Rotate (Cost: Navigation)
Shifts elements down. The last element becomes the first.
- `rra` : Shift down all elements of stack A by 1.
- `rrb` : Shift down all elements of stack B by 1.
- `rrr` : `rra` and `rrb` at the same time.

---

## 🚀 Algorithm Strategy

The program chooses a strategy based on the number of inputs (N) to optimize the move count.

### 1. Parsing & Initialization
- Check for errors: non-integers, duplicates, or numbers exceeding `MAX_INT` / `MIN_INT`.
- Parse arguments into the Linked List structure.
- **Indexing:** Assign an index (0 to N-1) to each number based on its value. This allows us to sort based on relative rank rather than raw values.

### 2. Tiny Sort (N ≤ 3)
- Hardcoded logic to sort 2 or 3 numbers in ≤ 2 moves.
- Checks the `top`, `middle`, and `bottom` to decide whether to swap or rotate.

### 3. Small Sort (N ≤ 5)
- Push the smallest numbers to Stack B until only 3 remain in Stack A.
- Run **Tiny Sort** on Stack A.
- Push elements back from B to A.

### 4. Big Sort (Radix or Chunking)
For large lists (100 or 500 numbers), simple recursion fails. We use a custom algorithm (e.g., Radix Sort or Turk Algorithm).
1.  **Push to B:** Move numbers from A to B in "chunks" or based on bitwise logic (Radix), keeping B partially sorted or identifying "cheapest" nodes.
2.  **Sort B:** Arrange B in descending order.
3.  **Push to A:** Move everything back to A. Since B is sorted, A becomes sorted instantly.

---

## 📦 Compilation & Usage

### 1. Compilation
Use the `Makefile` to compile the project.
```bash
make