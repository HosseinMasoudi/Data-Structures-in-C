# Bubble Sort Implementation in C

This repository contains a simple yet efficient implementation of the **Bubble Sort** algorithm in C. The code sorts an integer array in ascending order and includes optimizations for better performance.

## Algorithm Overview

Bubble Sort works by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. This process repeats until the largest elements "bubble up" to their correct positions at the end of the array.

### Key Features
- **Early Termination:** Includes a `swapped` flag. If no swaps occur during a pass, the algorithm stops, making it highly efficient for nearly sorted arrays.
- **In-place Sorting:** Does not require extra memory ($O(1)$ space).
- **Stable Sort:** It is a **Stable** algorithm, meaning it preserves the relative order of equal elements.

## Complexity Analysis

The performance of Bubble Sort depends on the initial order of the elements:

### 1. Comparisons
The main comparison occurs at: `if (a[j] > a[j+1])`
- **Worst Case (Descending Order):** The total number of comparisons is:
  $$\frac{n(n-1)}{2}$$
- **Best Case (Already Sorted):** Thanks to the optimized flag, only one pass is needed:
  $$n-1$$

### 2. Swaps (Data Movement)
The `swap(&a[j], &a[j+1])` function is called:
- **Worst Case (Descending Order):**
  $$\frac{n(n-1)}{2}$$
- **Best Case (Already Sorted):**
  $$0$$

| Case | Time Complexity |
| :--- | :--- |
| **Best Case** | $O(n)$ |
| **Average Case** | $O(n^2)$ |
| **Worst Case** | $O(n^2)$ |

## Characteristics
- **In-place:** The algorithm is **In-place**, requiring no additional data structures.
- **Stability:** It is a **Stable** sorting method, ensuring that equal values maintain their original relative positions.

## Code Structure

| Function | Description |
| :--- | :--- |
| `main()` | Initializes the array, calls the sort function, and manages I/O. |
| `BubbleSort()` | Implements the core logic with early termination optimization. |
| `printArray()` | Utility function to display array elements. |
| `swap()` | Exchanges two integer values using pointers. |

## Compilation and Execution

1. **Compile the program:**
   ```bash
   gcc bubblesort.c -o bubblesort
   ```
2. **Run the executable:**
   ```bash
   ./bubblesort
   ```
