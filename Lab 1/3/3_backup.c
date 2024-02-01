#include <stdio.h>

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    // Check if the number of rows is equal to the number of columns
    if (rows != cols) {
        printf("ERROR\n");
        return 0;
    }

    int matrix[rows][cols];

    // Input matrix elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate sum of primary diagonal
    int primary_sum = 0;
    for (int i = 0; i < rows; i++) {
        primary_sum += matrix[i][i];
    }

    // Calculate sum of secondary diagonal
    int secondary_sum = 0;
    for (int i = 0; i < rows; i++) {
        secondary_sum += matrix[i][rows - i - 1];
    }

    // Output sums
    printf("Primary: %d\n", primary_sum);
    printf("Secondary: %d\n", secondary_sum);

    return 0;
}
