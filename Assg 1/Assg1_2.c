//Assignment 2.3 : Symmetric Matrix
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

int isSymmetric(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int isSkewSymmetric(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != -matrix[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (isSymmetric(matrix, m, n)) {
        printf("The matrix is symmetric\n");
    } else if (isSkewSymmetric(matrix, m, n)) {
        printf("The matrix is skew-symmetric\n");
    } else {
        printf("None\n");
    }
    return 0;
}