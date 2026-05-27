# Selection Sort Implementation in C

This repository contains a clean, educational implementation of the **Selection Sort** algorithm written in the C programming language. It is designed to help beginners understand the fundamental mechanics of sorting algorithms and pointer manipulation in C.

## What is Selection Sort?

Selection Sort is a simple, intuitive comparison-based sorting algorithm. It works by dividing the input list into two parts: the sublist of items already sorted (which is built up from left to right) and the sublist of items remaining to be sorted.

### How it works:
1.  **Find the Minimum:** It starts at the beginning of the array and searches for the smallest element in the unsorted portion.
2.  **Swap:** Once the minimum element is found, it is swapped with the first element of the unsorted portion.
3.  **Repeat:** The boundary of the sorted portion moves one element to the right, and the process repeats until the entire array is sorted.

**Time Complexity:** $O(n^2)$
**Space Complexity:** $O(1)$ (It is an in-place sorting algorithm).

## Features
- **Randomized Input:** Generates random integers for the array, allowing you to test the algorithm with different datasets easily.
- **Pointer Manipulation:** Demonstrates proper use of pointers and memory swapping in C.
- **User Input Validation:** Handles array size inputs safely to prevent buffer overflows.

## How to Run

1.  **Clone the repository** (or download the source code).
2.  **Compile the code** using a C compiler (like GCC):
    ```bash
    gcc -o selection_sort main.c
    ```
3.  **Run the executable:**
    ```bash
    ./selection_sort
    ```
4.  **Enter the number of elements** when prompted, and the program will generate, sort, and display the results.

## Prerequisites
- A C compiler (e.g., `gcc`, `clang`, or any IDE like VS Code, CLion, or Dev-C++).
- Basic knowledge of C (for modifying or testing the code).

