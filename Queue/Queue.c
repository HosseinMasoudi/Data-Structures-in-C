#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
    int items[MAX_SIZE];
    int front; //head
    int rear; //tail
} Queue;

void initializeQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return q->front == -1;
}

bool isFull(Queue *q)
{
    return q->rear == MAX_SIZE - 1;
}

void enQueue(Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }

    q->items[q->rear] = value;
}

void deQueue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
}

int peek(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->items[q->front];
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue q;
    initializeQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    enQueue(&q, 30);

    display(&q);

    printf("Front element: %d\n", peek(&q));

    deQueue(&q);
    display(&q);

    printf("Front element after dequeue: %d\n", peek(&q));

    return 0;
}
