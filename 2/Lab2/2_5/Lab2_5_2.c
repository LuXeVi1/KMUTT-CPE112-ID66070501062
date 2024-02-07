#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point to itself for circularity
        return newNode;
    }

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; // Make it circular
    return head;
}

// Function to delete the first occurrence of a node with given data
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If the first node contains the key
    if (temp->data == key) {
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = temp->next;
        head = head->next;
        free(temp);
        return head;
    }

    // Find the node to be deleted
    while (temp->data != key && temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    // Node with 'key' not found
    if (temp->data != key) {
        return head;
    }

    // Unlink the node from the circular list
    prev->next = temp->next;
    free(temp);
    return head;
}

// Function to display the circular linked list
void displayList(Node* head) {
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
    char command[3];
    int value;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "E") == 0) {
            break;
        } else if (strcmp(command, "I") == 0) {
            scanf("%d", &value);
            head = insertNode(head, value);
        } else if (strcmp(command, "D") == 0) {
            scanf("%d", &value);
            head = deleteNode(head, value);
        }
    }

    displayList(head);
    
    // Free memory
    Node* temp = head;
    if (temp != NULL) {
        Node* current = temp;
        while (current->next != head) {
            temp = current;
            current = current->next;
            free(temp);
        }
        free(current);
    }

    return 0;
}
