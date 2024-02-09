//Assignment 3.2 : Palindrome Checker
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int capacity;
    char* array;
} Stack;

Stack* createStack(int capacity, char* array) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = array;
    return stack;
}

void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack* stack) {
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    return stack->array[stack->top];
}

int isPalindrome(char str[], int length, Stack* stack) {
    int i;
    for (i = 0; i < length / 2; i++) {
        push(stack, str[i]);
    }

    int start = (length % 2 == 0) ? length / 2 : length / 2 + 1;
    for (i = start; i < length; i++) {
        if (str[i] != pop(stack)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[101];
    scanf("%s", str);
    int length = strlen(str);

    char* stackArray = (char*)malloc(length * sizeof(char));
    Stack* stack = createStack(length, stackArray);

    if (isPalindrome(str, length, stack)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    free(stackArray);
    free(stack);

    return 0;
}
