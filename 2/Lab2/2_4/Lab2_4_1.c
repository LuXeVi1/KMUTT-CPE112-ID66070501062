//️Lab 2.4 : Linked List that can Go Back
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;
Node* tail = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void addNode(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL) temp->prev->next = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;
            if (temp == tail) tail = temp->prev;
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void searchNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("%d %s\n", temp->prev ? temp->prev->data : -1, temp->next ? temp->next->data : "NULL");
            return;
        }
        temp = temp->next;
    }
    printf("none\n");
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printListReverse(Node* head) {
    Node* temp = tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    char command[4];
    int data;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "END") == 0) {
            printList(head);
            printListReverse(head);
            break;
        } else {
            if (strcmp(command, "ADD") == 0 || strcmp(command, "DEL") == 0) {
                scanf("%d", &data);
                if (strcmp(command, "ADD") == 0) {
                    addNode(data);
                } else {
                    deleteNode(data);
                }
            } else if (strcmp(command, "SCH") == 0) {
                scanf("%d", &data);
                searchNode(data);
            }
        }
    }

    return 0;
}
