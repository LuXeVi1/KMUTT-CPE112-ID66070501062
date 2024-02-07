//Assignment 2.2 : Circular table
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

int findLastRemainingDigitIndex(int size, int step) {
    int index = 0;
    for (int i = 2; i <= size; i++) {
        index = (index + step) % i;
    }
    return index;
}

int findLastRemainingDigit(int numbers[], int size, int step) {
    int index = findLastRemainingDigitIndex(size, step);
    return numbers[index];
}

int main() {
    int size, step;

    if (scanf("%d %d", &size, &step) != 2 || size <= 0 || step <= 0) {
        printf("Invalid input. Size and step must be positive integers.\n");
        exit(EXIT_FAILURE);
    }

    int *numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input for number %d.\n", i + 1);
            free(numbers);
            exit(EXIT_FAILURE);
        }
    }

    int lastRemainingDigit = findLastRemainingDigit(numbers, size, step);

    printf("%d\n", lastRemainingDigit);

    free(numbers);

    return 0;
}
