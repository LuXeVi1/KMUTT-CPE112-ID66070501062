//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int rows, int cols, int **matrix) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", *(matrix + i) + j);
        }
    }
}

int main() {
    int rows, cols;
    scanf("%d %d", &rows, &cols);

    if (rows != cols) {
        printf("ERROR\n");
        return 0;
    }

    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    read_matrix(rows, cols, matrix);

    int primary_sum = 0, secondary_sum = 0;
    for (int i = 0; i < rows; i++) {
        primary_sum += *(*(matrix + i) + i);
        secondary_sum += *(*(matrix + i) + (cols - i - 1));
    }

    printf("Primary: %d\n", primary_sum);
    printf("Secondary: %d\n", secondary_sum);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}