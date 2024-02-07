#include <stdio.h>
#include <math.h>

int isPrime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int i = 3; i <= 1000000; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}