//Assignment 3.4 : Infix to Postfix
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Stack {
    int top;
    char array[MAX_SIZE];
} Stack;

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

char peek(Stack* stack) {
    return stack->array[stack->top];
}

char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void infixToPostfix(char* exp) {
    int i, k;
    Stack stack;
    stack.top = -1;

    for (i = 0, k = -1; exp[i]; ++i) {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(&stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                exp[++k] = pop(&stack);
            if (!isEmpty(&stack) && peek(&stack) != '(')
                return;
            else
                pop(&stack);
        } else {
            while (!isEmpty(&stack) && Prec(exp[i]) <= Prec(peek(&stack)))
                exp[++k] = pop(&stack);
            push(&stack, exp[i]);
        }
    }
    while (!isEmpty(&stack))
        exp[++k] = pop(&stack);
    exp[++k] = '\0';
    printf("%s\n", exp);
}

int main() {
    char exp[MAX_SIZE];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
