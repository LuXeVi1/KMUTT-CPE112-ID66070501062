//Arkkhanirut Pandej 66070501062

#include <stdio.h>

void printArray(int n, int *arr, int mode) {
    int i;
    int printed = 0;
    
    if (mode == 0) {
        for (i = 0; i < n; i += 2) {
            printf("%d ", arr[i]);
            printed = 1;
        }
    } else if (mode == 1) {
        for (i = 1; i < n; i += 2) {
            printf("%d ", arr[i]);
            printed = 1;
        }
    }
    
    if (!printed) {
        printf("none");
    }
}

int main() {
    int n, mode;
    scanf("%d", &n);
    int arr[n];
    
    // Input array elements
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    // Input mode
    scanf("%d", &mode);
    
    // Print array according to the mode
    printArray(n, arr, mode);
    
    return 0;
}
