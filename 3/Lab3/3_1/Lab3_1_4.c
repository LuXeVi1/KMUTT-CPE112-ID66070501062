//️Lab 3.1 : Stack Array
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int max_size;

void push(int data) {
    if (top == max_size - 1) {
        printf("Stack Overflow.\n");
        exit(0);
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow.\n");
        exit(0);
    }
    return stack[top--];
}

void show() {
    if (top == -1) {
        printf("Stack is empty.\n");
        exit(0);
    }
    for (int i = top; i >= 0; i--)
        printf("%d\n", stack[i]);
}

int main() {
    scanf("%d", &max_size);
    if (max_size <= 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }
    stack = (int*)malloc(max_size * sizeof(int));
    while (1) {
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int data;
                scanf("%d", &data);
                push(data);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                show();
                return 0;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                return 0;
        }
    }
    return 0;
}