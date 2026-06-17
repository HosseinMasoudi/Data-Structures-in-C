# Queue Implementation in C (Array-Based)

This project demonstrates a simple **Queue (FIFO) implementation in C using a static array**.  
The program supports basic queue operations such as **enqueue, dequeue, peek, and display**.

The implementation is designed for educational purposes and is useful for understanding how queues work internally in **Data Structures**.

---

# What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO (First In, First Out)** principle.

This means:

- The **first element inserted** into the queue is the **first element removed**.

Real-life example:

```
People waiting in a line
```

The first person in line is served first.

---

# Queue Structure

The queue is implemented using a **fixed-size array**.

```c
#define MAX_SIZE 100
```

Structure definition:

```c
typedef struct
{
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;
```

### Variables

- **items[]** → stores queue elements  
- **front** → index of the first element  
- **rear** → index of the last element  

---

# Queue Operations

## 1. Initialize Queue

Initializes the queue by setting both `front` and `rear` to `-1`.

```c
void initializeQueue(Queue *q)
```

This indicates that the queue is **empty**.

---

## 2. Check if Queue is Empty

```c
bool isEmpty(Queue *q)
```

The queue is empty when:

```
front == -1
```

---

## 3. Check if Queue is Full

```c
bool isFull(Queue *q)
```

The queue is full when:

```
rear == MAX_SIZE - 1
```

---

## 4. Enqueue (Insert Element)

```c
void enQueue(Queue *q, int value)
```

Adds an element to the **rear (tail)** of the queue.

Steps:

1. Check if the queue is full
2. If the queue is empty → set `front = 0`
3. Increment `rear`
4. Insert the element

Example:

```
Queue: 10 20 30
```

---

## 5. Dequeue (Remove Element)

```c
void deQueue(Queue *q)
```

Removes the element from the **front (head)** of the queue.

Cases handled:

- If queue is empty → error message
- If the queue has only one element → reset queue
- Otherwise → increment `front`

Example:

```
Before: 10 20 30
After dequeue: 20 30
```

---

## 6. Peek

```c
int peek(Queue *q)
```

Returns the **front element** without removing it.

Example:

```
Queue: 10 20 30
peek → 10
```

---

## 7. Display Queue

```c
void display(Queue *q)
```

Prints all elements from **front to rear**.

Example output:

```
Queue elements: 10 20 30
```

---

# Example Program Output

```
Queue elements: 10 20 30
Front element: 10
Queue elements: 20 30
Front element after dequeue: 20
```

---

# Time Complexity

| Operation | Complexity |
|--------|--------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |
| Display | O(n) |

---

# How to Compile and Run

### Compile

```bash
gcc queue.c -o queue
```

### Run

```bash
./queue
```

---

# Limitations

This implementation uses a **fixed-size array**, so:

- The queue size is limited to `MAX_SIZE`
- Memory freed by `deQueue` **cannot be reused**

A better alternative in real applications is:

- **Circular Queue**
- **Queue using Linked List**

---

# File Structure

```
queue.c
README.md
```
