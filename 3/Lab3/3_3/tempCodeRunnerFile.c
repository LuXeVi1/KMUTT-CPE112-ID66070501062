//️Lab 3.3 : Tower of Hanoi
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod, int *moves) {
    char *result = malloc(1024 * sizeof(char));
    result[0] = '\0';

    if (n == 1) {
        char buffer[50];
        sprintf(buffer, "Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        strcat(result, buffer);
        (*moves)++;
    } else {
        char *part1 = towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, moves);
        char buffer[50];
        sprintf(buffer, "Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        strcat(result, part1);
        strcat(result, buffer);
        (*moves)++;
        char *part2 = towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, moves);
        strcat(result, part2);
        free(part1);
        free(part2);
    }

    return result;
}

int main() {
    int n, moves = 0;
    scanf("%d", &n);
    char *result = towerOfHanoi(n, 'A', 'C', 'B', &moves);
    printf("%s", result);
    printf("Total moves: %d\n", moves);
    free(result);
    return 0;
}