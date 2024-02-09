//Assignment 3.3 : Parenthesis Checker
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct Stack {
    int top;
    char array[MAX_SIZE];
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    if (stack->top != -1)
        return stack->array[stack->top--];
    return '\0';
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

int areParenthesisBalanced(char exp[], int length) {
    int i = 0;

    Stack* stack = createStack(length);
    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (!isMatchingPair(pop(stack), exp[i])) {
                return 0;
            }
        }
        i++;
    }

    return stack->top == -1;
}

int main() {
    char exp[MAX_SIZE];
    scanf("%s", exp);

    int length = strlen(exp);

    if (areParenthesisBalanced(exp, length))
        printf("The string is balanced\n");
    else
        printf("The string is not balanced\n");

    return 0;
}
