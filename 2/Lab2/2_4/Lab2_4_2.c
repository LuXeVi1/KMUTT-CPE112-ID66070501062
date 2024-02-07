#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* addNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* deleteNode(Node* head, int key) {
    Node* current = head;
    if (head == NULL) {
        return NULL;
    }
    if (head->data == key) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
        return head;
    }
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        return head;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    free(current);
    return head;
}

void searchNode(Node* head, int key) {
    Node* current = head;
    while (current != NULL && current->data != key) {
        current = current->next;
    }
    if (current == NULL) {
        printf("none\n");
        return;
    }
    if (current->prev != NULL) {
        printf("%d ", current->prev->data);
    } else {
        printf("NULL ");
    }
    if (current->next != NULL) {
        printf("%d\n", current->next->data);
    } else {
        printf("NULL\n");
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void printListReverse(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node* head = NULL;
    char command[4];
    int isEmpty = 0; // Flag to track if the list is empty after DEL 1

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "END") == 0) {
            break;
        }
        int value;
        scanf("%d", &value);
        if (strcmp(command, "ADD") == 0) {
            head = addNode(head, value);
        } else if (strcmp(command, "DEL") == 0) {
            head = deleteNode(head, value);
            if (head == NULL) {
                isEmpty = 1; // Set flag to indicate empty list after DEL 1
            }
        } else if (strcmp(command, "SCH") == 0) {
            searchNode(head, value);
        }
    }

    if (isEmpty) {
        printf("none\nnone\n");
    } else {
        printList(head);
        printListReverse(head);
    }

    freeList(head);
    return 0;
}
