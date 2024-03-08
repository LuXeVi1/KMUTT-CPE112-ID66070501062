//Assignment 6.1: Kth Smallest Element in a BST
//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertNode(root->left, val);
    } else if (val > root->val) {
        root->right = insertNode(root->right, val);
    }

    return root;
}

void inorderTraversal(struct TreeNode* root, int* count, int k, int* result) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left, count, k, result);
    (*count)++;
    if (*count == k) {
        *result = root->val;
        return;
    }
    inorderTraversal(root->right, count, k, result);
}

char* kthSmallest(struct TreeNode* root, int k) {
    int count = 0;
    int result = -1;
    inorderTraversal(root, &count, k, &result);
    if (result == -1) {
        return "none";
    } else {
        char* resStr = (char*)malloc(12 * sizeof(char)); // Enough to hold all numbers up to 32 bit integer sizes
        sprintf(resStr, "%d", result);
        return resStr;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);

    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (i == 0) {
            root = createNode(val);
        } else {
            insertNode(root, val);
        }
    }

    scanf("%d", &k);
    char* kth_smallest = kthSmallest(root, k);
    printf("%s\n", kth_smallest);

    return 0;
}