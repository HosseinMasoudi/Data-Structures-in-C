#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX][MAX];   /*Stack of Strings*/
    int top;
} Stack;

void push(Stack *s, char *str);
void pop(Stack *s, char *res);
int isEmpty(Stack *s);
int isOperator(char c);
void postfixToInfix(char *postfix);

void push(Stack *s, char *str) {
    if (s->top < MAX - 1) {
        strcpy(s->items[++(s->top)], str);
    }
}

void pop(Stack *s, char *res) {
    if (s->top >= 0) {
        strcpy(res, s->items[(s->top)--]);
    }
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void postfixToInfix(char *postfix) {
    Stack s;
    s.top = -1;
    char operand1[MAX], operand2[MAX], temp[MAX];

    for (int i = 0; postfix[i] != '\0'; i++) {
        char token = postfix[i];

        /* If token is operand, push it to stack */
        if (isalnum(token)) {
            char str[2] = {token, '\0'};
            push(&s, str);
        } 
        /* If token is operator, pop two operands and combine them */
        else if (isOperator(token)) {
            pop(&s, operand2);
            pop(&s, operand1);

            /* Create a sub-expression: (operand1 operator operand2) */
            sprintf(temp, "(%s%c%s)", operand1, token, operand2);
            
            /* Push the result back to stack */
            push(&s, temp);
        }
    }

    /* The final element in stack is the complete infix expression */
    char finalInfix[MAX];
    pop(&s, finalInfix);
    printf("Infix Expression: %s\n", finalInfix);
}

int main() {
    char postfix[] = "ABCD^E-*+";
    printf("Postfix Expression: %s\n", postfix);
    postfixToInfix(postfix);
    return 0;
}
