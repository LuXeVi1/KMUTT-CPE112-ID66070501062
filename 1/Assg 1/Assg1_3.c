//Assignment 2.3 : Spiral Array Printer
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    int i, k = 0, l = 0;
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            printf("%d ", matrix[k][i]);
        }
        k++;
        for (i = k; i < m; ++i) {
            printf("%d ", matrix[i][n-1]);
        }
        n--;
        if (k < m) {
            for (i = n-1; i >= l; --i) {
                printf("%d ", matrix[m-1][i]);
            }
            m--;
        }
        if (l < n) {
            for (i = m-1; i >= k; --i) {
                printf("%d ", matrix[i][l]);
            }
            l++;
        }
    }
    return 0;
}