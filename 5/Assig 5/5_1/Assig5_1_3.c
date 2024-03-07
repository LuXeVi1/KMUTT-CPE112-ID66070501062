//Lab 5.1: Sum Tree
//Arkkhanirut Pandej 66070501062

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

bool isSumTree(struct Node* node, int* sum) {
    if (node == NULL) {
        *sum = 0;
        return true;
    }

    int leftSum, rightSum;
    bool isLeftSumTree = isSumTree(node->left, &leftSum);
    bool isRightSumTree = isSumTree(node->right, &rightSum);

    *sum = node->data + leftSum + rightSum;

    if (!isLeftSumTree || !isRightSumTree)
        return false;

    if (node->left == NULL && node->right == NULL)
        return true;

    return node->data == leftSum + rightSum;
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

    int sum;
    if (isSumTree(root, &sum))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}