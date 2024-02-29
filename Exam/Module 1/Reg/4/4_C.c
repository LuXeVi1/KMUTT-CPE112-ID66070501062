#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int peek(Node** head) {
    return (*head)->data;
}

void pop(Node** head) {
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(Node** head, int data) {
    Node* start = (*head);
    Node* temp = newNode(data);
    if ((*head)->data > data) {
        temp->next = *head;
        (*head) = temp;
    } else {
        while (start->next != NULL && start->next->data < data) {
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
}

void display(Node** head) {
    Node* start = (*head);
    while (start != NULL) {
        printf("%d ", start->data);
        start = start->next;
    }
    printf("\n");
}

int isEmpty(Node** head) {
    return (*head) == NULL;
}

int minSum(int arr[], int n) {
    Node* pq = newNode(arr[0]);
    for (int i = 1; i < n; i++)
        push(&pq, arr[i]);

    int num1 = 0, num2 = 0;
    while (!isEmpty(&pq)) {
        num1 = num1 * 10 + peek(&pq);
        pop(&pq);
        if (!isEmpty(&pq)) {
            num2 = num2 * 10 + peek(&pq);
            pop(&pq);
        }
    }

    return num1 + num2;
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("Invalid\n");
        return 0;
    }
    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    Node* pq = newNode(arr[0]);
    for (int i = 1; i < n; i++)
        push(&pq, arr[i]);
    display(&pq);
    printf("%d\n", peek(&pq));
    pop(&pq);
    pop(&pq);
    display(&pq);
    printf("Minimum sum is %d\n", minSum(arr, n));
    return 0;
}