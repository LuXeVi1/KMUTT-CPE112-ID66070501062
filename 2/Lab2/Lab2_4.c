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

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

Node* deleteNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        if (temp == head) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
        }
        free(temp);
    }
    return head;
}

void searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }
    if (temp != NULL) {
        printf("%d %d\n", temp->prev ? temp->prev->data : -1, temp->next ? temp->next->data : -1);
    } else {
        printf("none\n");
    }
}

void printList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("none\n");
    } else {
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void printListReverse(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("none\n");
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->prev;
        }
        printf("\n");
    }
}

int main() {
    char command[4];
    int data;
    Node* head = NULL;

    while (scanf("%s", command) && strcmp(command, "END") != 0) {
        if (strcmp(command, "ADD") == 0) {
            scanf("%d", &data);
            head = insertNode(head, data);
        } else if (strcmp(command, "DEL") == 0) {
            scanf("%d", &data);
            head = deleteNode(head, data);
        } else if (strcmp(command, "SCH") == 0) {
            scanf("%d", &data);
            searchNode(head, data);
        }
    }

    printList(head);
    printListReverse(head);

    return 0;
}
