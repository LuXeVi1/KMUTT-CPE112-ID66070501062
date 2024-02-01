//Assignment 2.2 : Jump Game
// Arkkhanirut Pandej 66070501062

#include <stdio.h>

// function to find the minimum number of jumps to reach arr[n-1] from arr[0]
int minJumps(int arr[], int n) {
    if (arr[0] == 0) 
        return -1;

    if (n == 1) 
        return 0;

    int jumps = 1;
    int maxReach = arr[0];
    int steps = arr[0];

    for (int i = 1; i < n; i++) {
        if (i == n - 1) 
            return jumps;

        maxReach = (maxReach > i + arr[i]) ? maxReach : i + arr[i];

        steps--;

        if (steps == 0) {
            jumps++;
            if (i >= maxReach) 
                return -1;
            steps = maxReach - i;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = minJumps(arr, n);
    if (result == -1) 
        printf("Not Possible\n");
    else 
        printf("%d\n", result);

    return 0;
}
