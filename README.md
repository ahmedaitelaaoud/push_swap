# 🦋 Push_swap

![Score](https://img.shields.io/badge/Score-100%2F100-brightgreen?style=for-the-badge&logo=42)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Algorithm](https://img.shields.io/badge/Algorithm-Chunking%20%2F%20Butterfly-orange?style=for-the-badge)

**"Because Swap_push isn't as natural."**

This project involves sorting data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (optimized for data sorting) for determining the "best" steps.

---

## 🚀 The Algorithm: The "Butterfly" Strategy

Unlike standard sorting algorithms (Quicksort, Merge Sort), `push_swap` restricts us to two stacks and specific operations. This project uses a **Dynamic Chunking Strategy** (often called the "Butterfly" method) to achieve 5-star performance.

### 🔢 Phase 1: Normalization & Indexing
The algorithm doesn't care about the actual values (e.g., `-2147483648`, `42`, `999`). It only cares about their **Rank**.
1.  Input is parsed and checked for errors (duplicates, non-integers).
2.  Values are assigned an index from `0` to `N-1` based on their size.
    * *Example:* `[-50, 100, 2]` → `[0, 2, 1]`

### 🦋 Phase 2: The Butterfly (Stack A -> Stack B)
We push numbers from **A** to **B** in chunks, creating a distribution curve in B (Butterfly shape). We define a dynamic `range` (window size).

* **If `index <= i` (Small):** Push to B (`pb`) and rotate B (`rb`) to send it to the bottom.
* **If `index <= i + range` (Medium):** Push to B (`pb`). It stays at the top.
* **If `index > i + range` (Large):** Rotate A (`ra`). Keep it for later.

This ensures that Stack B is built with the largest numbers concentrated near the top and middle, and smallest at the bottom.

### 🎯 Phase 3: The Return (Stack B -> Stack A)
Now Stack B is roughly sorted (large items are easy to access).
1.  Find the position of the **maximum index** in B.
2.  Calculate the cost: Is it faster to rotate up (`rb`) or reverse-rotate down (`rrb`)?
3.  Move max to top and push to A (`pa`).
4.  Repeat until B is empty.

---

## 🛠️ Instruction Set

The project allows the following operations to manipulate the stacks:

| Command | Description |
| :--- | :--- |
| **`sa`** | Swap the first 2 elements at the top of stack A. |
| **`sb`** | Swap the first 2 elements at the top of stack B. |
| **`ss`** | `sa` and `sb` at the same time. |
| **`pa`** | Take the first element at the top of B and put it at the top of A. |
| **`pb`** | Take the first element at the top of A and put it at the top of B. |
| **`ra`** | Shift all elements of stack A up by 1. The first element becomes the last one. |
| **`rb`** | Shift all elements of stack B up by 1. The first element becomes the last one. |
| **`rr`** | `ra` and `rb` at the same time. |
| **`rra`** | Shift all elements of stack A down by 1. The last element becomes the first one. |
| **`rrb`** | Shift all elements of stack B down by 1. The last element becomes the first one. |
| **`rrr`** | `rra` and `rrb` at the same time. |

---

## ⚙️ Compilation & Usage

### Build
Run the following command to compile the executable `push_swap`:
```bash
make
