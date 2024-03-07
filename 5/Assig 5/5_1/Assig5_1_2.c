#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int sumOfSubtree(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->data + sumOfSubtree(node->left) + sumOfSubtree(node->right);
}

bool isSumTree(struct Node* node) {
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return true;

    int leftSum = sumOfSubtree(node->left);
    int rightSum = sumOfSubtree(node->right);

    if ((node->data == leftSum + rightSum) && isSumTree(node->left) && isSumTree(node->right))
        return true;
    else
        return false;
}

int main() {
    struct Node* root = NULL;
    struct Node* nodes[1000] = {NULL}; 
    int front = 0, rear = 0;

    int value;
    while (scanf("%d", &value) == 1 && value != -1001) {
        struct Node* node = newNode(value);

        if (root == NULL) {
            root = node;
        } else {
            if (nodes[front]->left == NULL) {
                nodes[front]->left = node;
            } else if (nodes[front]->right == NULL) {
                nodes[front]->right = node;
                front++;
            }
        }

        nodes[rear++] = node;
    }

    if (isSumTree(root))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}