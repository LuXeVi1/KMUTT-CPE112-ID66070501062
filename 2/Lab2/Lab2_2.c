//️Lab 2.2 : Before or After Insertion
// Arkkhanirut Pandej 66070501062
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void displayList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct node *insertAfter(struct node *head, int key, int data) {
    struct node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                return head;
            }
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

struct node *insertBefore(struct node *head, int key, int data) {
    struct node *temp = head;
    if (temp != NULL && temp->data == key) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return head;
        }
        newNode->data = data;
        newNode->next = temp;
        return newNode;
    }
    while (temp != NULL && temp->next != NULL) {
        if (temp->next->data == key) {
            struct node *newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL) {
                printf("Memory allocation failed\n");
                return head;
            }
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void deleteList(struct node *head) {
    struct node *temp = head;
    struct node *nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *newNode = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }
        newNode->data = value;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    char mode;
    int key, data;
    while (scanf(" %c", &mode) == 1 && mode != 'E') {
        if (mode == 'A' || mode == 'B') {
            scanf("%d %d", &key, &data);
            if (mode == 'A') {
                head = insertAfter(head, key, data);
            } else {
                head = insertBefore(head, key, data);
            }
        }
    }

    displayList(head);
    deleteList(head);

    return 0;
}