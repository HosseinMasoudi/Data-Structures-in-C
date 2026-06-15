#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) 
{
    s->top = -1;
}

bool isEmpty(Stack* s) 
{
    return s->top == -1;
}

bool isFull(Stack* s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, int value) 
{
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

int pop(Stack* s) 
{
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop from an empty stack\n");
        return -1; // Return -1 to indicate stack is empty
    }
    int poppedValue = s->arr[s->top];
    s->top--;
    printf("Popped %d from the stack\n", poppedValue);
    return poppedValue;
}

int peek(Stack* s) 
{
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return s->arr[s->top];
}

int main()
{
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    printf("Top element is: %d\n", peek(&stack));
    push(&stack, 20);
    printf("Top element is: %d\n", peek(&stack));
    push(&stack, 30);
    printf("Top element is: %d\n", peek(&stack));

    while(!isEmpty(&stack)) // instead of !isEmpty(&stack) we can also use isFull(&stack)
    {
        pop(&stack);
    }

    return 0;
}