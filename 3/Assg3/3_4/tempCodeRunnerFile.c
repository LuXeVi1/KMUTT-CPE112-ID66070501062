#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Stack {
    int top;
    char array[MAX_SIZE];
} Stack;

void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top != -1)
        return stack->array[stack->top--];
    return '\0';
}

char peek(Stack* stack) {
    return stack->array[stack->top];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack stack;
    stack.top = -1;

    int i = 0, j = 0;
    while (infix[i]) {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            char top = peek(&stack);
            while (stack.top != -1 && top != '(') {
                postfix[j++] = pop(&stack);
                top = peek(&stack);
            }
            if (stack.top != -1 && top == '(')
                pop(&stack); // Discard the '('
        } else if (isOperator(ch)) {
            char top = peek(&stack);
            while (stack.top != -1 && precedence(top) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
                top = peek(&stack);
            }
            push(&stack, ch);
        }
        i++;
    }

    while (stack.top != -1) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("%s\n", postfix);

    return 0;
}
