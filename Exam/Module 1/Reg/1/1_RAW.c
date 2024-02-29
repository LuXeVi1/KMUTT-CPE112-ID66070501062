#include <stdio.h>
#define ROWS 3
#define COLS 6

___ findAvg(___) {
    int x,y,sum,kx,ky;
    for (___; y++) {
        for (___; x++) {
            sum=0;
            for (___; ky++) {
                for (___; kx++) {
                    sum+=data[y+ky][x+kx];
                    }
                }
                data[y][x]=(int)sum/9;
            }
        }
}

void printData(___) {
    int x,y;
    for (y=0; y<ROWS; y++) {
        for (x=0; x<COLS; x++) {
            printf("%d ", data[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int input[ROWS][COLS]=
    {{ 1, 1, 1, 2, 2, 2},
    { 3, 3, 3, 4, 4, 4,},
    { 1, 1, 1, 2, 2, 2,},
    { 3, 3, 3, 4, 4, 4,}};

    findAvg(input);
    printData(input);
    return 0;
}