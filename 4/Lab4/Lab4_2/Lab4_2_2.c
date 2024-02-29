//️Lab 4.2 : เมื่อไหร่จะถึงคิวฉันบ้าง???
//Arkkhanirut Pandej 66070501062

#include <stdio.h>

#define MAX_SIZE 10

int front = -1, rear = -1;
int circularQ[MAX_SIZE];

int size;

void insertQueue(int data) {
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front)) {
        printf("Queue is full!!\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
        circularQ[rear] = data;
    } else if (rear == size - 1 && front != 0) {
        rear = 0;
        circularQ[rear] = data;
    } else {
        rear = (rear + 1) % size;
        circularQ[rear] = data;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return -1;
    }

    int data = circularQ[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return data;
}

void showQueue() {
    if (front == -1) {
        printf("Queue is empty!!\n");
        return;
    }

    printf("Front: %d\n", front);
    printf("Items: ");

    int i = front;
    do {
        printf("%d ", circularQ[i]);
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    
    printf("\n");
    printf("Rear: %d\n", rear);
}

void processInput() {
    char input;
    int data;
    while (1) {
        scanf(" %c", &input);
        if (input == 'I') {
            scanf("%d", &data);
            insertQueue(data);
        } else if (input == 'D') {
            data = dequeue();
            if (data != -1) {
                printf("%d\n", data);
            }
        } else if (input == 'S') {
            showQueue();
        } else if (input == 'E') {
            break;
        } else {
            printf("Invalid input!\n");
        }
    }
}

int main() {
    scanf("%d", &size);
    if (size > MAX_SIZE || size <= 0) {
        return 0;
    }

    processInput();

    return 0;
}
