//Assignment 3.1 : Ten to X
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>

const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void convertBase(int n, int base) {
    if (base < 2 || base > 36) {
        printf("invalid\n");
        return;
    }

    char *stack;
    int top = 0;

    int maxDigits = 1;
    int temp = n;
    while (temp /= base) {maxDigits++;}

    stack = (char *)malloc(maxDigits * sizeof(char));

    while (n > 0) {
        stack[top++] = digits[n % base];
        n /= base;
    }

    while (top > 0) {printf("%c", stack[--top]);}
    printf("\n");
    free(stack);
}

int main() {
    int n, base;
    scanf("%d %d", &n, &base);
    convertBase(n, base);
    return 0;
}