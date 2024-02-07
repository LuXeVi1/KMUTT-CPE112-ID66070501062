//️Lab 2.5 : Circular Linked List
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
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

Node* delete(Node* head, int data) {
    if (head == NULL) return head;
    Node* temp = head, *prev;
    if (temp->data == data) {
        if (temp->next == head) {
            free(temp);
            return NULL;
        }
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        return temp->next;
    }
    while (temp->next != head && temp->next->data != data) {
        temp = temp->next;
    }
    if (temp->next->data == data) {
        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = NULL;
    char command;
    int data;
    while (scanf(" %c", &command) != EOF) {
        if (command == 'I') {
            scanf("%d", &data);
            head = insert(head, data);
        } else if (command == 'D') {
            scanf("%d", &data);
            head = delete(head, data);
        } else if (command == 'E') {
            display(head);
            break;
        }
    }
    return 0;
}