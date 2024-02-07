//Challenge: List Slicing
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int* list = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    int start, end, step;
    scanf("%d %d %d", &start, &end, &step);

        if (start < 0) start = n + start;
    if (end < 0) end = n + end;

    if (start < 0) start = 0;
    if (end > n) end = n;

    if (step > 0) {
        for(int i = start; i < end; i += step) {
            if(i >= 0 && i < n) {
                printf("%d ", list[i]);
            }
        }
    } else {
        for(int i = start; i > end; i += step) {
            if(i >= 0 && i < n) {
                printf("%d ", list[i]);
            }
        }
    }

    free(list);

    return 0;
}
