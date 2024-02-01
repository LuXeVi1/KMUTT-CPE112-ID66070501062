//Assignment 2.3 : Spiral Array Printer
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int num1, num2;
    // printf("Enter the number of rows and columns: ");
    scanf("%d %d", &num1, &num2);

    int arr[MAX_SIZE][MAX_SIZE];

    // Input array elements
    // printf("Enter the elements of the array:\n");
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int top = 0, bottom = num1 - 1, left = 0, right = num2 - 1;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up

    // printf("Spiral Array Printer:\n");
    while (top <= bottom && left <= right) {
        if (direction == 0) { // Move from left to right
            for (int i = left; i <= right; i++) {
                printf("%d ", arr[top][i]);
            }
            top++;
        } else if (direction == 1) { // Move from top to bottom
            for (int i = top; i <= bottom; i++) {
                printf("%d ", arr[i][right]);
            }
            right--;
        } else if (direction == 2) { // Move from right to left
            for (int i = right; i >= left; i--) {
                printf("%d ", arr[bottom][i]);
            }
            bottom--;
        } else if (direction == 3) { // Move from bottom to top
            for (int i = bottom; i >= top; i--) {
                printf("%d ", arr[i][left]);
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }

    return 0;
}
