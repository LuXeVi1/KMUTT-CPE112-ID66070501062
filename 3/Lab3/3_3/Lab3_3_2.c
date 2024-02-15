//️Lab 3.3 : Tower of Hanoi
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

void towerOfHanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    towerOfHanoi(disks - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", disks, source, destination);
    towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main() {
    int disks;
    if (scanf("%d", &disks) != 1 || disks <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    towerOfHanoi(disks, 'A', 'B', 'C');
    printf("Total moves: %d\n", (1 << disks) - 1);

    return 0;
}
