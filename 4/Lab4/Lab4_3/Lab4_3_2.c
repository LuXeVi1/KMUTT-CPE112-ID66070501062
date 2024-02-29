#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001
#define VOWELS "aeiouAEIOU"
#define SYMBOLS "0123456789!@#$%^&*()_+-=[]{}|;':\",./<>? "
#define CONSONANTS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define NULL_CHARACTER '\0'

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** listHead, Node** listTail, char data) {
    Node* newNode = createNode(data);
    if (*listHead == NULL) {
        *listHead = newNode;
    } else {
        (*listTail)->next = newNode;
    }
    *listTail = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* prioritizing(char* input) {
    Node* head = NULL;
    Node* tail = NULL;
    Node* symbolsHead = NULL;
    Node* symbolsTail = NULL;
    Node* consonantsHead = NULL;
    Node* consonantsTail = NULL;

    for (int i = 0; input[i] != NULL_CHARACTER; i++) {
        char ch = input[i];
        if (strchr(VOWELS, ch) != NULL) {
            insert(&head, &tail, ch);
        } else if (strchr(SYMBOLS, ch) != NULL) {
            insert(&symbolsHead, &symbolsTail, ch);
        } else if (strchr(CONSONANTS, ch) != NULL) {
            insert(&consonantsHead, &consonantsTail, ch);
        }
    }

    if (tail != NULL) {
        tail->next = symbolsHead;
    } else {
        head = symbolsHead;
    }

    if (symbolsTail != NULL) {
        symbolsTail->next = consonantsHead;
    } else if (tail == NULL) {
        head = consonantsHead;
    }

    return head;
}

int main() {
    char string[MAX_SIZE];
    fgets(string, sizeof(string), stdin);
    Node* result = prioritizing(string);
    display(result);
    freeList(result);
    return 0;
}
