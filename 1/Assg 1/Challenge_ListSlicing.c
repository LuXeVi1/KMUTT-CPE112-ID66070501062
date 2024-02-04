//Challenge: List Slicing
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int elements[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }
    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);
    int printed = 0;
    for (int i = start; i < end; i += step) {
        printf("%d ", elements[i]);
        printed = 1;
    }
    if (!printed) {
        printf("empty");
    }
    return 0;
}