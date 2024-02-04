//️Lab 2.3 : Where to Delete?
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

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
    if (head == NULL) {
        head = createNode(data);
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = createNode(data);
    }
    return head;
}

Node* deleteFirstNode(Node* head) {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return head;
}

Node* deleteLastNode(Node* head) {
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            Node* secondLast = head;
            while (secondLast->next->next != NULL) {
                secondLast = secondLast->next;
            }
            free(secondLast->next);
            secondLast->next = NULL;
        }
    }
    return head;
}

Node* deleteNodeWithValue(Node* head, int value) {
    if (head != NULL) {
        Node* temp = head;
        Node* prev = NULL;
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            if (temp == head) {
                head = deleteFirstNode(head);
            } else {
                prev->next = temp->next;
                free(temp);
            }
        }
    }
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("none\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, data;
    char mode;
    Node* head = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    do {
        scanf(" %c", &mode);
        switch (mode) {
            case 'F':
                head = deleteFirstNode(head);
                break;
            case 'L':
                head = deleteLastNode(head);
                break;
            case 'N':
                scanf("%d", &data);
                head = deleteNodeWithValue(head, data);
                break;
            case 'E':
                break;
        }
    } while (mode != 'E');

    printList(head);

    return 0;
}