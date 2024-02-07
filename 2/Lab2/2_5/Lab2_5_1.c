//️Lab 2.5 : Circular Linked List
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    return head;
}

Node* deleteNode(Node* head, int value) {
    Node* temp = head;
    if (head->data == value) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
    } else {
        Node* prev = temp;
        temp = temp->next;
        while (temp != head && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != head) {
            prev->next = temp->next;
            free(temp);
        }
    }
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

int main() {
    char command[2];
    int data;
    Node* head = NULL;

    while (scanf("%s", command) && strcmp(command, "E") != 0) {
        if (strcmp(command, "I") == 0) {
            scanf("%d", &data);
            head = insertNode(head, data);
        } else if (strcmp(command, "D") == 0) {
            scanf("%d", &data);
            head = deleteNode(head, data);
        }
    }

    printList(head);

    return 0;
}