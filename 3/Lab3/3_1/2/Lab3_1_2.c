#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000000

typedef struct Stack {
    int top;
    int* array;
    int size;
} Stack;

Stack* createStack(int size) {
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid stack size.\n");
        exit(EXIT_FAILURE);
    }
    Stack* stack = (Stack*)malloc(sizeof(Stack) + size * sizeof(int));
    if (!stack) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    stack->size = size;
    stack->array = (int*)(stack + 1);
    return stack;
}

void push(Stack* stack, int x) {
    if (stack->top == stack->size - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    stack->array[++stack->top] = x;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}

void show(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->array[i]);
    }
}

int main() {
    int size, choice, x;
    scanf("%d", &size);
    Stack* stack = createStack(size);
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%d", &x);
                push(stack, x);
                break;
            case 2:
                pop(stack);
                break;
            case 3:
                show(stack);
                break;
            case 4:
                printf("Exiting...\n");
                free(stack);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
