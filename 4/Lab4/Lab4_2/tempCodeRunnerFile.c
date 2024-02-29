#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

// Structure to represent circular queue
struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
};

// Function prototypes
void initializeQueue(struct CircularQueue *q);
void insertq(struct CircularQueue *q, int value, int size);
int dequeue(struct CircularQueue *q, int size);
void show(struct CircularQueue *q, int size);

int main() {
    struct CircularQueue q;
    initializeQueue(&q);

    int size, value;
    char command;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    // Consume the newline character
    getchar();

    // Initialize the queue
    initializeQueue(&q);

    while (1) {
        printf("Enter command (I xxx, D, S, E): ");
        scanf("%c", &command);

        if (command == 'E') {
            break;
        } else if (command == 'I') {
            scanf("%d", &value);
            insertq(&q, value, size);
        } else if (command == 'D') {
            int dequeuedValue = dequeue(&q, size);
            if (dequeuedValue != -1)
                printf("%d\n", dequeuedValue);
        } else if (command == 'S') {
            show(&q, size);
        }

        // Consume the newline character
        getchar();
    }

    return 0;
}

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to insert a value into the circular queue
void insertq(struct CircularQueue *q, int value, int size) {
    if ((q->front == 0 && q->rear == size - 1) || (q->rear == (q->front - 1) % (size - 1))) {
        printf("Queue is full!!\n");
        return;
    } else if (q->front == -1) {
        q->front = q->rear = 0;
    } else if (q->rear == size - 1 && q->front != 0) {
        q->rear = 0;
    } else {
        q->rear++;
    }

    q->items[q->rear] = value;
}

// Function to dequeue a value from the circular queue
int dequeue(struct CircularQueue *q, int size) {
    if (q->front == -1) {
        printf("Queue is empty!!\n");
        return -1;
    }

    int value = q->items[q->front];
    q->items[q->front] = -1;

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == size - 1) {
        q->front = 0;
    } else {
        q->front++;
    }

    return value;
}

// Function to display the circular queue
void show(struct CircularQueue *q, int size) {
    if (q->front == -1) {
        printf("Queue is empty!!\n");
        return;
    }

    printf("Front: %d\n", q->front);
    printf("Items: ");
    int i = q->front;
    if (q->rear >= q->front) {
        while (i <= q->rear)
            printf("%d ", q->items[i++]);
    } else {
        while (i < size)
            printf("%d ", q->items[i++]);
        i = 0;
        while (i <= q->rear)
            printf("%d ", q->items[i++]);
    }
    printf("\n");
    printf("Rear: %d\n", q->rear);
}
