//Assignment 2.1 : It's Sorting Time
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int score;
    struct Node* next;
} Node;

Node* createNode(int id, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int id, int score) {
    Node* newNode = createNode(id, score);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void sortList(Node** head, int mode) {
    Node *i, *j;
    for (i = *head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if ((mode == 0 && i->id > j->id) || (mode == 1 && (i->score > j->score || (i->score == j->score && i->id > j->id)))) {
                int tempId = i->id;
                int tempScore = i->score;
                i->id = j->id;
                i->score = j->score;
                j->id = tempId;
                j->score = tempScore;
            }
        }
    }
}

int main() {
    Node* head = NULL;
    int size, id, score, mode;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &id, &score);
        insertNode(&head, id, score);
    }
    scanf("%d", &mode);
    sortList(&head, mode);
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->score);
        temp = temp->next;
    }
    return 0;
}