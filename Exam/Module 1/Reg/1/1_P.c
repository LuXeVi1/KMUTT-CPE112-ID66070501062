#include <stdio.h>
#define ROWS 4
#define COLS 6

void findAvg(int data[ROWS][COLS]) {
    int x, y, sum, kx, ky;
    for (y = 1; y < ROWS - 1; y++) {
        for (x = 1; x < COLS - 1; x++) {
            sum = 0;
            for (ky = -1; ky <= 1; ky++) {
                for (kx = -1; kx <= 1; kx++) {
                    sum += data[y + ky][x + kx];
                }
            }
            data[y][x] = sum / 9;
        }
    }
}

void printData(int data[ROWS][COLS]) {
    int x, y;
    for (y = 0; y < ROWS; y++) {
        for (x = 0; x < COLS; x++) {
            printf("%d ", data[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int input[ROWS][COLS] = {
        {1, 1, 1, 2, 2, 2},
        {3, 3, 3, 4, 4, 4},
        {1, 1, 1, 2, 2, 2},
        {3, 3, 3, 4, 4, 4}
    };

    findAvg(input);
    printData(input);
    return 0;
}
