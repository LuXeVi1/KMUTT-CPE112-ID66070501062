//Arkkhanirut Pandej 66070501062

#include <stdio.h>

#define MAX_SIZE 10000

void print_element_and_index(int *arr, int index) {
    printf("%d %d\n", *(arr + index), index);
}

void find_min_max(int *arr, int n, int *min_index, int *max_index) {
    *min_index = 0;
    *max_index = 0;

    for (int i = 1; i < n; i++) {
        if (*(arr + i) < *(arr + *min_index)) {
            *min_index = i;
        }
        if (*(arr + i) > *(arr + *max_index)) {
            *max_index = i;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    int min_index, max_index;
    find_min_max(arr, n, &min_index, &max_index);

    print_element_and_index(arr, max_index);
    print_element_and_index(arr, min_index);

    return 0;
}