#include <stdio.h>

#define SIZE 10

int queue[SIZE];
int front = -1, rear = -1;

void insert(int value) {
    if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
        printf("Queue is full!!\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        queue[rear] = value;
    } else if (rear == SIZE - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
    } else {
        rear++;
        queue[rear] = value;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }
    printf("%d\n", queue[front]);
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1)
        front = 0;
    else
        front++;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }
    printf("Front: %d\n", front);
    printf("Items: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < SIZE; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\nRear: %d\n", rear);
}

int main() {
    int size, value;
    char command;
    scanf("%d", &size);
    while (scanf(" %c", &command) != EOF) {
        if (command == 'I') {
            scanf("%d", &value);
            insert(value);
        } else if (command == 'D') {
            dequeue();
        } else if (command == 'S') {
            display();
        } else if (command == 'E') {
            break;
        }
    }
    return 0;
}