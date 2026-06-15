# Stack Implementation

## Description

This project is a simple fixed-size stack implementation written in C. It demonstrates the core Last-In, First-Out (LIFO) behavior of a stack using an array and provides the basic operations needed to work with it:

- `push` to add an item
- `pop` to remove the most recent item
- `peek` to view the top item without removing it
- `isEmpty` and `isFull` to check stack state

The `main()` function includes a small demo that pushes a few values, prints the top element, and then pops all values from the stack.

## Features

- Array-based stack implementation
- Fixed maximum size defined by `MAX_SIZE`
- Overflow protection when the stack is full
- Underflow protection when the stack is empty
- Simple console output for each stack operation
- Beginner-friendly example of stack fundamentals in C

## Technologies Used

- C
- Standard C libraries:
  - `stdio.h`
  - `stdbool.h`

## Installation

1. Make sure you have a C compiler installed.
   - On Linux or macOS, `gcc` or `clang` will work.
   - On Windows, you can use MinGW, WSL, or another C toolchain.
2. Clone or download this repository.
3. Open a terminal in the project root.
4. Build the program:

```bash
gcc Stack/Stack.c -o stack
```

5. Run the executable:

```bash
./stack
```

## Usage

The program is self-contained and runs the demonstration from `main()` automatically.

Example output may look like this:

```text
Pushed 10 onto the stack
Top element is: 10
Pushed 20 onto the stack
Top element is: 20
Pushed 30 onto the stack
Top element is: 30
Popped 30 from the stack
Popped 20 from the stack
Popped 10 from the stack
```

If you want to reuse the stack functions in another C file, you can call them like this:

```c
Stack stack;
initStack(&stack);

push(&stack, 10);
push(&stack, 20);

printf("Top element: %d\n", peek(&stack));
pop(&stack);
```
