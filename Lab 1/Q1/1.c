//Arkkhanirut Pandej 66070501062

#include <stdio.h>

int main() {
    int n, i, current, count;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    // sort the array
    for(i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    current = arr[0];
    count = 1;
    for(i=1; i<n; i++) {
        if(arr[i] == current) {
            continue;
        }
        current = arr[i];
        count++;
    }

    printf("Number of distinct elements: ");
    printf("%d\n", count);
    for(i=0; i<n; i++) {
        if(i != 0 && arr[i] == arr[i-1]) {
            continue;
        }
        printf("%d ", arr[i]);
    }
    return 0;
}