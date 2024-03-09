#include <stdio.h>

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int set1[] = {1, 2, 2, 3, 4, 4, 5};
    int size1 = sizeof(set1) / sizeof(set1[0]);
    printf("Original array: ");
    printArray(set1, size1);
    removeDuplicatesAndSort(set1, &size1);
    printf("After removing duplicates and sorting: ");
    printArray(set1, size1);

    int set2[] = {1, 1, 1, 1, 1};
    int size2 = sizeof(set2) / sizeof(set2[0]);
    printf("Original array: ");
    printArray(set2, size2);
    removeDuplicatesAndSort(set2, &size2);
    printf("After removing duplicates and sorting: ");
    printArray(set2, size2);

    int set3[] = {5, 4, 3, 2, 1};
    int size3 = sizeof(set3) / sizeof(set3[0]);
    printf("Original array: ");
    printArray(set3, size3);
    removeDuplicatesAndSort(set3, &size3);
    printf("After removing duplicates and sorting: ");
    printArray(set3, size3);

    return 0;
}