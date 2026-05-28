# Binary Search in C

This repository contains a simple and educational implementation of **Binary Search** in the C programming language.  
It includes:

- An **iterative** binary search function (`BinSearch`)
- A **recursive** binary search function (`BinSearchRecursive`) *(see note below about the return type)*

The sample `main()` demonstrates searching for a target value inside a sorted integer array.

---

## What is Binary Search?

**Binary Search** is an efficient searching algorithm used to find an element in a **sorted array**.

Instead of scanning the array linearly, Binary Search repeatedly:

1. Checks the middle element
2. Discards half of the remaining search range based on comparison
3. Continues until the value is found or the search range becomes empty

Because the search space is cut in half each step, the algorithm runs in **logarithmic time**.

---

## Requirement (Very Important)

Binary Search works correctly **only if the array is sorted** (ascending in this project).  
If the array is not sorted, the result is undefined/incorrect.

---

## How the Iterative Version Works

The iterative function keeps two indices:

- `left`  : start of the current search range
- `right` : end of the current search range

It computes:

```c
middle = (left + right) / 2;
```

Then compares `list[middle]` with `SearchNum`:

- If `list[middle] < SearchNum` → move `left` to `middle + 1`
- If `list[middle] == SearchNum` → return `middle`
- If `list[middle] > SearchNum` → move `right` to `middle - 1`

---

## COMPARE Macro

This project uses a helper macro:

```c
#define COMPARE(x,y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0 : 1 )
```

It returns:

- `-1` if `x < y`
- `0`  if `x == y`
- `1`  if `x > y`

This makes the `switch` logic in the search functions clean and readable.

---

## Complexity

Let `n` be the number of elements.

### Time Complexity
- **Best Case:** `O(1)` (target is exactly the middle element at the first step)
- **Worst Case:** `O(log n)` (range halves repeatedly)
- **Average Case:** `O(log n)`

### Space Complexity
- **Iterative:** `O(1)`
- **Recursive:** `O(log n)` due to the call stack

---

## Example Output

With:

```c
int list[] = {1,3,5,7,9,11,13,15,17,19};
int SearchNum = 7;
```

The program prints:

```bash
Element found at index: 3
```

---

## Build & Run

### Compile
```bash
gcc binary_search.c -o binary_search
```

### Run
```bash
./binary_search
```

---

## Notes About the Recursive Function (Fix Needed)

In the provided code, `BinSearchRecursive` is declared as `void`, but it returns values like `-1` and `middle`.  
This is not valid in C.

### Correct prototype should be:
```c
int BinSearchRecursive(int list[], int SearchNum, int left, int right);
```

And the function definition must also return `int`.

If you want, I can send the corrected recursive function code as well.

---

## Summary

- Binary Search is a fast searching algorithm for **sorted arrays**
- It uses a **divide-and-conquer** strategy (halve the search space each step)
- Runs in `O(log n)` time and is very efficient for large datasets