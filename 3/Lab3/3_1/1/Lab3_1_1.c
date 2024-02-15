//️Lab 3.1 : Stack Array
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000000

int stack[MAX_SIZE];
int top = -1;

int isFull();
int isEmpty();

void push(int x) {
    if (isFull()) {
        printf("Stack Overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack[++top] = x;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        exit(EXIT_FAILURE);
    }
    top--;
}

void show() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

int main() {
    int size;
    scanf("%d", &size);
    if (size <= 0) {
        printf("Please enter a positive number.\n");
        exit(EXIT_FAILURE);
    }
    while (1) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            int x;
            scanf("%d", &x);
            push(x);
        } else if (operation == 2) {
            pop();
        } else if (operation == 3) {
            show();
            exit(EXIT_SUCCESS);
        } else if (operation == 4) {
            printf("Exiting...\n");
            exit(EXIT_SUCCESS);
        } else {
            printf("Invalid choice.\n");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}
