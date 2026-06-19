Hossein، این یک **README.md حرفه‌ای و مناسب GitHub** برای پروژه *Queue using Two Stacks in C* است. می‌توانی مستقیماً در ریپازیتوری قرار بدهی.

:::writing
# Queue Implementation Using Two Stacks in C

This project demonstrates how to implement a **Queue (FIFO)** using **two Stacks (LIFO)** in the C programming language.

The implementation uses **dynamic memory allocation**, **modular design**, and **linked lists** to represent stacks. It is intended as an educational example for understanding **data structure transformation** and **amortized time complexity**.

---

# Overview

A **Queue** follows the **FIFO (First In, First Out)** principle.

Example:

First element inserted → First element removed

```
Queue:

10 → 20 → 30

Dequeue → 10
```

A **Stack**, on the other hand, follows **LIFO (Last In, First Out)**.

```
Stack:

Push: 10, 20, 30

Pop → 30
```

This project shows how we can simulate FIFO behavior using **two LIFO structures**.

---

# Key Idea

Two stacks are used:

```
stack_in   → used for enqueue operations
stack_out  → used for dequeue operations
```

### Enqueue Operation

When adding an element to the queue:

```
push(element) → stack_in
```

Example:

```
stack_in: 30 20 10
```

---

### Dequeue Operation

When removing an element:

1. If `stack_out` is empty
2. Move all elements from `stack_in` to `stack_out`
3. Pop from `stack_out`

This reverses the order and produces **FIFO behavior**.

Example:

```
stack_in: 30 20 10

transfer →

stack_out: 10 20 30

pop → 10
```

---

# Project Structure

```
queue_two_stacks.c
README.md
```

---

# Data Structures

## Node (Linked List)

Each stack node stores a value and a pointer to the next node.

```
typedef struct Node
{
    int data;
    struct Node *next;
} Node;
```

---

## Stack

Stacks are implemented using **linked lists**.

```
typedef struct
{
    Node *top;
    int size;
} Stack;
```

---

## Queue

The queue contains two stacks.

```
typedef struct
{
    Stack *stack_in;
    Stack *stack_out;
} Queue;
```

---

# Supported Operations

### enqueue()

Adds an element to the queue.

```
enqueue(q, value)
```

Internally pushes the element to `stack_in`.

---

### dequeue()

Removes and returns the **front element** of the queue.

If `stack_out` is empty, elements are transferred from `stack_in`.

---

### peek()

Returns the **front element** without removing it.

---

### isEmpty()

Checks whether the queue contains any elements.

---

### size()

Returns the total number of elements in the queue.

---

# Example Output

```
Enqueue elements: 10, 20, 30

Front element: 10
Queue size: 3

Dequeue: 10
Dequeue: 20

Front element: 30
Queue size: 1

Dequeue: 30
Dequeue: 40
```

---

# Time Complexity

| Operation | Complexity |
|----------|-----------|
| enqueue | O(1) |
| dequeue | amortized O(1) |
| peek | amortized O(1) |
| isEmpty | O(1) |
| size | O(1) |

### Why amortized O(1)?

Occasionally, elements must be moved from `stack_in` to `stack_out`.

This transfer costs **O(n)**, but each element is moved **only once**, so the average cost per operation remains **O(1)**.

---

# Memory Management

This implementation uses **dynamic memory allocation**:

```
malloc()
free()
```

Memory is released using:

```
freeStack()
freeQueue()
```

This prevents **memory leaks**.

---

# How to Compile and Run

### Compile

```
gcc queue_two_stacks.c -o queue
```

### Run

```
./queue
```

---

# Why This Implementation Is Useful

This approach demonstrates several important computer science concepts:

- Data structure composition
- Stack and queue behavior
- Amortized time complexity
- Dynamic memory management in C
- Linked list based stack implementation

This problem is also a **common coding interview question**.

---

# Limitations

Although educational, this approach has some drawbacks:

- Requires **two stacks instead of one queue**
- Implementation is more complex than a normal queue
- Worst-case dequeue operation is **O(n)**

For most practical systems, a **circular queue** or **linked-list queue** is simpler.

