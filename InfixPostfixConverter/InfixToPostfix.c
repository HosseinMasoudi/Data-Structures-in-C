#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct Stack {
    char items[MAX];
    int top;
} Stack;


int isEmpty(Stack *s);
void Push(Stack *s, char item);
char Pop(Stack *s);
char Peek(Stack *s);

void Push(Stack *s, char item)
{
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = item;
} 

char Pop(Stack *s)
{
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[s->top--];
}

char Peek(Stack *s)
{
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

int isEmpty(Stack *s)
{
    return s->top == -1;
}

int precedence(char op)
{
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void InfixToPostfix(char *infix, char *postfix)
{
    Stack s;
    s.top = -1;
    int j = 0;

    for (int i = 0; infix[i]; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token;
        } else if (token == '(') {
            Push(&s, token);
        } else if (token == ')') {
            while (!isEmpty(&s) && Peek(&s) != '(') {
                postfix[j++] = Pop(&s);
            }
            Pop(&s); // Remove '(' from stack
        } else {
            while (!isEmpty(&s) && precedence(Peek(&s)) >= precedence(token)) {
                postfix[j++] = Pop(&s);
            }
            Push(&s, token);
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = Pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main()
{
    char postfix[MAX];
    char infix[] = "A+B*(C^D-E)";

    InfixToPostfix(infix, postfix);
    printf("Infix expression:   %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}