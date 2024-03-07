 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int sum(Node* node) {
    if(node == NULL)
        return 0;
    return sum(node->left) + node->data + sum(node->right);
}

bool isSumTree(Node* node) {
    int ls, rs;

    if(node == NULL || (node->left == NULL && node->right == NULL))
        return true;

    ls = sum(node->left);
    rs = sum(node->right);

    return (node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right);
}

int main() {
    Node *root  = newNode(26);
    root->left         = newNode(10);
    root->right        = newNode(3);
    root->left->left   = newNode(4);
    root->left->right  = newNode(6);
    root->right->right = newNode(3);

    if(isSumTree(root))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}