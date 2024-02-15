#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100000000

int stack[MAX_SIZE];
int top = -1;

bool isEmpty() {
    return top == -1;
}

bool isFull(int size) {
    return top == size - 1;
}

void push(int value, int size) {
    if (isFull(size)) {
        printf("Stack Overflow.\n");
        return;
    }
    top++;
    stack[top] = value;
}

void pop() {
    if (isEmpty()) {
        printf("Stack Underflow.\n");
        return;
    }
    top--;
}

void show() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int size;
    scanf("%d", &size);

    if (size <= 0) {
        printf("Please enter a positive number.\n");
        return 0;
    }

    int choice, value;
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &value);
                push(value, size);
                break;
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
