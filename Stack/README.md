# Stack Implementation in C (Array-Based)

This project provides a simple and educational implementation of a **Stack** data structure in the C programming language using a **static array**.

The program demonstrates the basic stack operations such as **push**, **pop**, and **peek**, along with helper functions to check whether the stack is **empty** or **full**.

---

## What is a Stack?

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

This means the **last element inserted into the stack is the first one to be removed**.

Common real-world examples include:

- Function call stack in programs
- Undo/Redo operations in editors
- Expression evaluation
- Backtracking algorithms

---

## Stack Operations Implemented

This implementation supports the following operations:

### `initStack(Stack* s)`
Initializes the stack by setting the `top` index to `-1`.

### `push(Stack* s, int value)`
Adds a new element to the **top of the stack**.

If the stack is full, a **Stack Overflow** message is displayed.

### `pop(Stack* s)`
Removes the **top element** from the stack and returns it.

If the stack is empty, a **Stack Underflow** message is displayed.

### `peek(Stack* s)`
Returns the element at the **top of the stack** without removing it.

### `isEmpty(Stack* s)`
Checks whether the stack is empty.

### `isFull(Stack* s)`
Checks whether the stack is full.

---

## Data Structure

The stack is implemented using a `struct`:

```c
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;
```

- `arr[MAX_SIZE]` → stores the stack elements
- `top` → index of the current top element

The maximum stack capacity is defined by:

```c
#define MAX_SIZE 100
```

---

## Example Program Behavior

The `main()` function demonstrates stack usage:

1. Initialize the stack
2. Push elements (`10`, `20`, `30`)
3. Print the top element after each push using `peek`
4. Pop elements until the stack becomes empty

Example output:

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

---

## Time Complexity

| Operation | Time Complexity |
|-----------|----------------|
| Push      | O(1) |
| Pop       | O(1) |
| Peek      | O(1) |
| isEmpty   | O(1) |
| isFull    | O(1) |

All operations run in **constant time** because they only involve accessing the top index.

---

## Build and Run

### Compile

```bash
gcc stack.c -o stack
```

### Run

```bash
./stack
```

---

## Project Structure

```
stack.c      # Main source code implementing the stack
README.md    # Project documentation
```

---

## Notes

- This implementation uses a **fixed-size array**, so the stack capacity is limited.
- Overflow occurs when trying to push elements beyond `MAX_SIZE`.
- Underflow occurs when trying to pop from an empty stack.

---
