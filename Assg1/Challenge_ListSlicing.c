//Challenge: List Slicing
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, start, end, step;
    
    // printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    m = n;

    // Allocate memory for list
    int *list = (int *)malloc(n * sizeof(int));
    
    // printf("Enter the elements of the list separated by space: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // printf("Enter the start, end, and step values: ");
    scanf("%d %d %d", &start, &end, &step);

    if (step > 0) {
        for (int i = start; i < end; i += step) {
            printf("%d ", list[i]);
        }
    } else if (step < 0) {
        for (int i = start; i > end; i += step) {
            printf("%d ", list[i]);
        }
    }

    // Free memory
    free(list);

    return 0;
}
