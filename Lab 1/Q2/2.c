//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

// Function to create a new node for the interval tree
typedef struct Node {
    int start, end, max;
    struct Node *left, *right;
} Node;

// Function to create a new node with the given parameters
Node* newNode(int start, int end, int max) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->start = start;
    node->end = end;
    node->max = max;
    node->left = node->right = NULL;
    return node;
}

// Function to find the maximum value in the interval tree node
int getMax(Node* root) {
    if (root == NULL)
        return -1;
    return root->max;
}

// Function to update the maximum value in the interval tree node
void updateMax(Node* root, int val) {
    if (root != NULL) {
        root->max = (val > root->max) ? val : root->max;
    }
}

// Function to insert a new interval into the interval tree
Node* insert(Node* root, int start, int end, int val) {
    // If the tree is empty
    if (root == NULL) {
        return newNode(start, end, val);
    }

    // If the new interval is before the current root, go left
    if (start < root->start) {
        root->left = insert(root->left, start, end, val);
    }

    // If the new interval is after the current root, go right
    else if (end > root->end) {
        root->right = insert(root->right, start, end, val);
    }

    // If the new interval overlaps with the current root, update the maximum value
    else {
        updateMax(root, val);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to find the maximum water level in the given array of intervals
int maxWaterLevel(int* arr, int n) {
    // Create an empty interval tree
    Node* root = NULL;

    // Initialize the maximum water level to 0
    int maxWaterLevel = 0;

    // Iterate over the intervals in the array
    for (int i = 0; i < n; i++) {
        // Insert the current interval into the interval tree
        root = insert(root, arr[i], arr[i], arr[i]);

        // Compute the maximum water level that can be held by the current interval
        int maxLeft = getMax(root->left);
        int maxRight = getMax(root->right);

        // Update the maximum water level if necessary
        maxWaterLevel = (maxLeft > maxRight) ?
                       (maxWaterLevel > maxLeft ? maxWaterLevel : maxLeft) :
                       (maxWaterLevel > maxRight ? maxWaterLevel : maxRight);
    }

    // Return the maximum water level
    return maxWaterLevel;
}

int main() {
    // Read the number of test cases
    int t;
    scanf("%d", &t);

    // Process each test case
    while (t-- > 0) {
        // Read the number of intervals and the height of the container
        int n, h;
        scanf("%d %d", &n, &h);

        // Read the intervals
        int* arr = (int*) malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Compute the maximum water level
        int maxWaterLevel = maxWaterLevel(arr, n);

        // Print the maximum water level or an empty line
        if (maxWaterLevel == 0) {
            printf("empty\n");
        } else {
            for (int i = 0; i < h; i++) {
                if (i < maxWaterLevel) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }

        // Free the memory used by the array
        free(arr);
    }

    // Return 0 to indicate successful termination
    return 0;
}