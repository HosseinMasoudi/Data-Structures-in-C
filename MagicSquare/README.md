# Magic Square Generator (Odd Order) in C

This project is a simple C program that generates an **N × N Magic Square** for an **odd** integer `N` (between **1** and **15**).

A **magic square** is a square grid filled with the numbers `1` to `N²` such that the sum of every row, every column, and both main diagonals is the same constant (called the **magic constant**).

---

## How It Works (Siamese Method)

This program uses the classic **Siamese method** (also known as the De la Loubère method) for constructing odd-order magic squares:

1. Start by placing `1` in the **top middle** cell.
2. For each next number (`2` to `N²`):
   - Move **one row up** and **one column left** (wrapping around the edges).
   - If the target cell is already occupied, move **one row down** instead (from the current position).
3. Repeat until the square is filled.

The program implements wrap-around behavior using the ternary operator:

```c
row    = (i - 1 < 0) ? (size - 1) : (i - 1);   // move up (wrap to bottom)
column = (j - 1 < 0) ? (size - 1) : (j - 1);   // move left (wrap to right)
```

---

## Input Constraints

- The size must be:
  - **Odd**
  - Between **1** and **15**

If the input is invalid, the program prints an error message and exits.

---

## Magic Constant

For an `N × N` magic square, the sum of each row/column/diagonal equals:

\[
M = \frac{N(N^2 + 1)}{2}
\]

Example for `N = 3`:

\[
M = \frac{3(9 + 1)}{2} = 15
\]

---

## Example Output

For `N = 3`, one valid output is:

```text
The 3 x 3 magic square is:
   8    1    6
   3    5    7
   4    9    2
```

---

## Build and Run

### Compile
```bash
gcc magic_square.c -o magic_square
```

### Run
```bash
./magic_square
```

Then enter an odd number between `1` and `15` when prompted.

---

## Project Notes

- The program stores the square in a static 2D array:
  ```c
  static int square[MAX_SIZE][MAX_SIZE];
  ```
- Works for **odd** sizes only (the Siamese method is designed for odd-order squares).
- Maximum size is limited to **15** to keep memory usage small and output readable.

---

## Files

- `magic_square.c` — main C source code
