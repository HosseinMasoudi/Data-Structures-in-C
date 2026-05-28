# Selection Sort Implementation in C

This repository contains a clean, educational implementation of the **Selection Sort** algorithm written in the C programming language. It is designed to help beginners understand the fundamental mechanics of sorting algorithms and pointer manipulation in C.

## What is Selection Sort?

Selection Sort is a simple, intuitive comparison-based sorting algorithm. It works by dividing the input list into two parts: the sorted portion and the unsorted portion.

### How it works:
1.  **Find the Minimum:** It scans the unsorted portion to find the smallest element.
2.  **Swap:** It swaps the found minimum element with the first element of the unsorted portion.
3.  **Repeat:** The process repeats until the entire array is sorted.

## Complexity Analysis

The efficiency of the algorithm can be broken down into the number of comparisons and swaps:

*   **Total Comparisons:** The comparison statement `if (list[j] < list[min])` is executed:
    $$\frac{n(n-1)}{2}$$
    This remains constant regardless of the initial order of the elements.
*   **Total Swaps:** The `swap(&list[i], &list[min])` function is called:
    $$n-1$$
    This is one of the primary advantages of Selection Sort: it minimizes the number of swaps.

**Time Complexity:** $O(n^2)$  
**Space Complexity:** $O(1)$ (In-place algorithm)

## Stability and Characteristics

*   **In-place Algorithm:** It requires only a constant amount $O(1)$ of additional memory space.
*   **Unstable Sorting:** By default, Selection Sort is **Unstable**. This means it may change the relative order of elements with equal keys.
*   **Optimization Note:** Every unstable sorting algorithm can be transformed into a **Stable** one without increasing its asymptotic time complexity. For example, in Selection Sort, this can be achieved by considering the **original indices** of the elements during the comparison process to break ties.

## Features
- **Randomized Input:** Generates random integers to test the algorithm with different datasets.
- **Pointer Manipulation:** Demonstrates proper use of pointers and memory swapping in C.
- **User Input Validation:** Handles array size inputs safely to prevent buffer overflows.

## How to Run

1.  **Compile the code:**
    ```bash
    gcc -o selection_sort main.c
    ```
2.  **Run the executable:**
    ```bash
    ./selection_sort
    ```

## Prerequisites
- A C compiler (GCC, Clang, or any standard C IDE).
- Basic knowledge of C and Data Structures.
