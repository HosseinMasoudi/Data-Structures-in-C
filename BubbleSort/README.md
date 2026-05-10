# Bubble Sort Implementation in C

This repository contains a simple yet efficient implementation of the **Bubble Sort** algorithm in C. The code sorts an integer array in ascending order and includes functions for swapping elements and printing the array.

## Algorithm Overview

Bubble Sort works by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. The pass through the list is repeated until no swaps are needed, indicating that the list is sorted.

### Key Features
- **Early termination** – If no swaps occur during a full pass, the sorting stops early, making it efficient for nearly sorted arrays.
- **In-place sorting** – Sorts the array without using additional data structures.
- **Stable sort** – Maintains the relative order of equal elements.

## Code Structure

| Function       | Description                                                                 |
|----------------|-----------------------------------------------------------------------------|
| `main()`       | Initializes an integer array, prints it, calls `BubbelSort()`, and prints the sorted array. |
| `BubbelSort()` | Implements the bubble sort logic with a `swapped` flag for optimization.    |
| `printArray()` | Prints all elements of the array to the console.                            |
| `swap()`       | Swaps two integer values using pointers.                                    |

> **Note:** The function name `BubbelSort` contains a small typo (missing "b"), but the code compiles and runs correctly. You may rename it to `BubbleSort` if desired.

## Compilation and Execution

### Prerequisites
- A C compiler (e.g., `gcc`, `clang`)

### Steps
1. Save the code in a file named `bubblesort.c`
2. Open a terminal in the directory containing the file
3. Compile the program:
   ```bash
   gcc bubblesort.c -o bubblesort```
