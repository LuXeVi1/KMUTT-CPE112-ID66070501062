//Assignment 2.3 : Reverse Linked List
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

ListNode* createNode(int val) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void insertNode(ListNode **head, int val) {
    ListNode *newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void reverse(ListNode **head, int start, int end) {
    if (start >= end) return;
    ListNode *prev = NULL, *curr = *head, *next = NULL;
    int count = 1;
    while (curr != NULL && count < start) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    ListNode *connection = prev, *tail = curr;
    while (curr != NULL && count <= end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (connection != NULL) {
        connection->next = prev;
    } else {
        *head = prev;
    }
    tail->next = curr;
}

void printList(ListNode *head) {
    ListNode *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    char input[100];
    ListNode *head = NULL;
    while (scanf("%s", input) && strcmp(input, "END") != 0) {
        insertNode(&head, atoi(input));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    reverse(&head, start, end);
    printList(head);
    return 0;
}