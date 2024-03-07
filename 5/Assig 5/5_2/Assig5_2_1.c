//Lab 5.2: Prefix to Postfix
//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};


struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct Node* add(struct Node* root, char data[], int* index) {
    if (data[*index] == '\0' || data[*index] == '\n') 
        return NULL;

    struct Node* node = newNode(data[*index]);
    (*index)++;

    if (data[*index-1] == '+' || data[*index-1] == '-') {
        node->left = add(node->left, data, index);
        node->right = add(node->right, data, index);
    }

    return node;
}


void post(struct Node* root) {
    if (root == NULL)
        return;

    post(root->left);
    post(root->right);
    printf("%c", root->data);
}

int main() {
    char prefix[100];
    struct Node* root = NULL;


    fgets(prefix, sizeof(prefix), stdin);

    int index = 0;
    root = add(root, prefix, &index);


    post(root);
    printf("\n");

    return 0;
}
