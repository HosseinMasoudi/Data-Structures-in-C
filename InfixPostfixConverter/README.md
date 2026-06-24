# Expression Conversion in C

This project contains two classic stack-based expression conversion programs written in C:

- `Infix to Postfix`
- `Postfix to Infix`

These implementations are designed for learning **Stack**, **expression parsing**, and **operator precedence** in Data Structures using the C programming language.

---

## Overview

Mathematical expressions can be written in different forms:

- **Infix**: `A + B * C`
- **Postfix**: `ABC*+`

These conversions are important in compiler design, expression evaluation, and stack-based parsing algorithms.

This repository demonstrates how to convert between these notations using the **Stack** data structure.

---

## Projects Included

### 1. Infix to Postfix
Converts an infix expression such as:

```text
A+B*(C^D-E)
```

into postfix form:

```text
ABCD^E-*+
```

This program uses a stack to temporarily store operators and parentheses while respecting:

- operator precedence
- parentheses handling
- correct output ordering

---

### 2. Postfix to Infix
Converts a postfix expression such as:

```text
ABCD^E-*+
```

into infix form:

```text
(A+(B*((C^D)-E)))
```

This program uses a stack of strings.  
Each operand is pushed into the stack, and when an operator is found, the top two expressions are popped, combined into a new infix sub-expression, and pushed back.

---

## Concepts Used

This project is useful for practicing the following concepts:

- Stack implementation
- Array-based stack in C
- Operator precedence
- Parentheses processing
- String manipulation in C
- Expression conversion algorithms

---

## File Structure

Example structure:

```text
.
├── InfixToPostfix.c
├── PostfixToInfix.c
└── README.md
```

If your filenames are different, update this section accordingly.

---

## Infix to Postfix Algorithm

The basic logic is:

1. If the token is an operand, add it directly to the output.
2. If the token is `(`, push it into the stack.
3. If the token is `)`, pop and output until `(` is found.
4. If the token is an operator:
   - pop operators from the stack while they have higher or equal precedence
   - then push the current operator
5. At the end, pop all remaining operators from the stack.

---

## Postfix to Infix Algorithm

The basic logic is:

1. If the token is an operand, push it as a string into the stack.
2. If the token is an operator:
   - pop the top two expressions
   - combine them as `(operand1 operator operand2)`
   - push the new string back into the stack
3. At the end, the stack contains the final infix expression.

---

## Why Stack Is Used

Stack is the ideal data structure for these problems because it follows **LIFO**:

- In `Infix to Postfix`, operators must be processed in reverse order of insertion depending on precedence.
- In `Postfix to Infix`, the most recent operands/sub-expressions must be combined first.

---

## Example

### Infix to Postfix

Input:

```text
A+B*(C^D-E)
```

Output:

```text
ABCD^E-*+
```

### Postfix to Infix

Input:

```text
ABCD^E-*+
```

Output:

```text
(A+(B*((C^D)-E)))
```

---

## Compilation

Use `gcc` to compile the programs.

### Compile Infix to Postfix

```bash
gcc InfixToPostfix.c -o infix_to_postfix
```

### Run

```bash
./infix_to_postfix
```

### Compile Postfix to Infix

```bash
gcc PostfixToInfix.c -o postfix_to_infix
```

### Run

```bash
./postfix_to_infix
```

---

## Time Complexity

### Infix to Postfix
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

### Postfix to Infix
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

Where `n` is the length of the expression.

---

These programs are intended for **educational purposes**.
