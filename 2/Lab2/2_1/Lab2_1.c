//️Lab 2.1 : Linked List Insertion
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void displayList(struct node *start) {
    struct node *ptr = start;
    if (ptr == NULL) {
        printf("None");
    }
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertNodeBegin(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertNodeEnd(struct node **head, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }
}

int main() {
    int n, option, data;
    scanf("%d", &n);
    if (n == 0) {
        printf("Invalid");
        return 0;
    }
    scanf("%d", &option);
    struct node *head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        if (option == 1) {
            insertNodeBegin(&head, data);
        } else if (option == 2) {
            insertNodeEnd(&head, data);
        } else {
            printf("Invalid");
            return 0;
        }
    }
    displayList(head);
    return 0;
}