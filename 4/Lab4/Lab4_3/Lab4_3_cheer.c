// Ponprathan Kuearung 66070501036

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1001
#define VOWELS "aeiouAEIOU"
#define SYMBOLS "0123456789!@#$%^&*()_+-=[]{}|;':\",./<>? "
#define CONSONANTS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;

}

void insert(Node** listHead, char data) {
    Node* newNode = createNode(data);
    if (*listHead == NULL) {
        *listHead = newNode;
        return;
    }

    Node* temp = *listHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

}

void display(Node* head) {
    while (head != NULL) {
        printf("%c", head->data);
        head = head->next;
    }
}

Node* prioritizing(char* input) {
    Node* head = NULL;
    // vowels
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Check if the character is a vowel
        if (strchr(VOWELS, ch) != NULL) {
            insert(&head, ch); // Insert vowel to the list
        }
    }
    // symbols
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Check if the character is a symbol
        if (strchr(SYMBOLS, ch) != NULL) {
            insert(&head, ch); // Insert symbol to the list
        }
    }
    // consonants
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Check if the character is an alphabet (not a vowel)
        if (strchr(CONSONANTS, ch) != NULL && strchr(VOWELS, ch) == NULL) {
            insert(&head, ch); // Insert alphabet to the list
        }
    }
    return head;
}

int main() {
    char string[MAX_SIZE];
    fgets(string, sizeof(string), stdin);
    Node* result = prioritizing(string);
    display(result);
    return 0;
}