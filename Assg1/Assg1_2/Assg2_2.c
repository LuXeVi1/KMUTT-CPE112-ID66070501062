#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    // Input matrix elements
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is symmetric
    int symmetric = 1; // Assume symmetric initially
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0; // If any element doesn't match its transpose, it's not symmetric
                break;
            }
        }
        if (!symmetric) {
            break;
        }
    }

    // Check if the matrix is skew-symmetric
    int skew_symmetric = 1; // Assume skew-symmetric initially
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != -matrix[j][i]) {
                skew_symmetric = 0; // If any element doesn't match the negative of its transpose, it's not skew-symmetric
                break;
            }
        }
        if (!skew_symmetric) {
            break;
        }
    }

    // Output the result
    if (symmetric) {
        printf("The matrix is symmetric\n");
    } else if (skew_symmetric) {
        printf("The matrix is skew-symmetric\n");
    } else {
        printf("None\n");
    }

    return 0;
}
