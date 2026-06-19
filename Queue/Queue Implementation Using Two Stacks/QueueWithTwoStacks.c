#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

typedef struct Stack
{
    Node* top;
    int size;
} Stack;

typedef struct Queue
{
    Stack* stack_in;
    Stack* stack_out;
} Queue;

Stack* createStack()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

bool stackIsEmpty(Stack* stack)
{
    return stack->size == 0;
}

void push(Stack* stack, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;
}

int pop(Stack* stack)
{
    if (stackIsEmpty(stack))
    {
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate stack is empty
    }
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

int stackpeek(Stack* stack)
{
    if (stackIsEmpty(stack))
    {
        printf("Stack is empty\n");
        return -1; // Return -1 to indicate stack is empty
    }
    return stack->top->data;
}

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack_in = createStack();
    queue->stack_out = createStack();
    return queue;
}

bool queueIsEmpty(Queue* queue)
{
    return stackIsEmpty(queue->stack_in) && stackIsEmpty(queue->stack_out);
}

int queueSize(Queue* queue)
{
    return queue->stack_in->size + queue->stack_out->size;
}

void enqueue(Queue* queue, int data)
{
    push(queue->stack_in, data);
}

int dequeue(Queue* queue)
{
    if (queueIsEmpty(queue))
    {
        printf("Queue underflow\n");
        return -1; // Return -1 to indicate queue is empty
    }
    if (stackIsEmpty(queue->stack_out))
    {
        while (!stackIsEmpty(queue->stack_in))
        {
            int data = pop(queue->stack_in);
            push(queue->stack_out, data);
        }
    }
    return pop(queue->stack_out);
}

int queuepeek(Queue* queue)
{
    if (queueIsEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1; // Return -1 to indicate queue is empty
    }
    if (stackIsEmpty(queue->stack_out))
    {
        while (!stackIsEmpty(queue->stack_in))
        {
            int data = pop(queue->stack_in);
            push(queue->stack_out, data);
        }
    }
    return stackpeek(queue->stack_out);
}

void freeStack(Stack* stack)
{
    while (!stackIsEmpty(stack))
    {
        pop(stack);
    }
    free(stack);
}

void freeQueue(Queue* queue)
{
    freeStack(queue->stack_in);
    freeStack(queue->stack_out);
    free(queue);
}

int main()
{
    Queue *q = createQueue();

    printf("Enqueue elements: 10, 20, 30\n");

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Front element: %d\n", queuepeek(q));
    printf("Queue size: %d\n", queueSize(q));

    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));

    printf("Front element: %d\n", queuepeek(q));
    printf("Queue size: %d\n", queueSize(q));

    enqueue(q, 40);

    printf("Dequeue: %d\n", dequeue(q));
    printf("Dequeue: %d\n", dequeue(q));

    freeQueue(q);

    return 0;
}