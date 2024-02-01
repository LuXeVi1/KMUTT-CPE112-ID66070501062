//Assignment 2.4 : Multiplication Matrix
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

int main() {
    int m, n, k, l;
    // printf("Enter the dimensions of the first matrix A (m n): ");
    scanf("%d %d", &m, &n);

    int A[m][n];
    // printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // printf("Enter the dimensions of the second matrix B (k l): ");
    scanf("%d %d", &k, &l);

    if (n != k) {
        printf("Not Compatible\n");
        return 0;
    }

    int B[k][l];
    // printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < l; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform matrix multiplication
    int C[m][l];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            C[i][j] = 0;
            for (int x = 0; x < n; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }

    // Output the result
    // printf("Resultant Matrix C:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
