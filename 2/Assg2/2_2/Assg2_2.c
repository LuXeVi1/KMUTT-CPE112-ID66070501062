#include <stdio.h>

int findLastRemainingDigit(int numbers[], int size, int step) {
    int index = 0;
    while (size > 1) {
        index = (index + step - 1) % size;
        for (int i = index; i < size - 1; i++) {numbers[i] = numbers[i + 1];}
        size--;
    }
    return numbers[0];
}

int main() {
    int size, step;
    scanf("%d %d", &size, &step);

    int numbers[size];
    for (int i = 0; i < size; i++) {scanf("%d", &numbers[i]);}

    int lastRemainingDigit = findLastRemainingDigit(numbers, size, step);

    printf("%d\n", lastRemainingDigit);

    return 0;
}
