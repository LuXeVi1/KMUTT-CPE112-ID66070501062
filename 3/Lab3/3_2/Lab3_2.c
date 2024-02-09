//️Lab 3.2 : Stack as Linked List
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = top;
    top = temp;
}

int pop() {
    if (top == NULL) {return -1;}

    Node* temp = top;
    top = top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek() {
    return (top != NULL) ? top->data : -1;
}

int main() {
    char command;
    int x;

    while ((command = getchar()) != EOF && command != 'q') {switch (command) {
            case 'p':
                scanf("%d", &x);
                push(x);
                break;
            case 'o':
                x = pop();
                if (x == -1) {
                    printf("empty\n");
                } else {
                    printf("%d\n", x);
                }
                break;
            case 't':
                x = peek();
                if (x == -1) {
                    printf("empty\n");
                } else {
                    printf("%d\n", x);
                }
                break;
            case 'e':
                printf("%d\n", (top == NULL));
                break;
        }
    }

    return 0;
}
