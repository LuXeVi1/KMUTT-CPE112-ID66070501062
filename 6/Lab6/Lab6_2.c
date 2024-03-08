//Lab 6.2: AVL Tree
//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int maxof(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = maxof(height(y->left), height(y->right)) + 1;
    x->height = maxof(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = maxof(height(x->left), height(x->right)) + 1;
    y->height = maxof(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + maxof(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

void postOrder(struct Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, data;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &data);
        root = insert(root, data);
    }
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);

    return 0;
}