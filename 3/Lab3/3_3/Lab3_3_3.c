#include <stdio.h>

void TowerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    static int count = 0;
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        count++;
        printf("Total moves: %d\n", count);
        return;
    }
    TowerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    count++;
    TowerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    if (n == 2) {
        printf("Total moves: %d\n", count);
    }
}

int main() {
    int n;
    // printf("Enter the number of disks: ");
    scanf("%d", &n);
    TowerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}