#include <stdio.h>
#include <stdlib.h>

// Function to print the elements of a set
void printSet(int set[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

// Function to perform union of two sets
void unionSets(int setA[], int sizeA, int setB[], int sizeB, int universe[], int universeSize) {
    int result[universeSize];
    int i, j, k;
    i = j = k = 0;

    while (i < sizeA && j < sizeB) {
        if (setA[i] < setB[j]) {
            result[k++] = setA[i++];
        } else if (setA[i] > setB[j]) {
            result[k++] = setB[j++];
        } else {
            result[k++] = setA[i++];
            j++;
        }
    }

    while (i < sizeA) {
        result[k++] = setA[i++];
    }

    while (j < sizeB) {
        result[k++] = setB[j++];
    }

    if (k == 0) {
        printf("empty\n");
    } else {
        printSet(result, k);
    }
}

// Function to perform intersection of two sets
void intersectSets(int setA[], int sizeA, int setB[], int sizeB) {
    int result[sizeA + sizeB];
    int i, j, k;
    i = j = k = 0;

    while (i < sizeA && j < sizeB) {
        if (setA[i] < setB[j]) {
            i++;
        } else if (setA[i] > setB[j]) {
            j++;
        } else {
            result[k++] = setA[i++];
            j++;
        }
    }

    if (k == 0) {
        printf("empty\n");
    } else {
        printSet(result, k);
    }
}

// Function to perform set difference (A - B)
void differenceSets(int setA[], int sizeA, int setB[], int sizeB) {
    int result[sizeA];
    int i, j, k;
    i = j = k = 0;

    while (i < sizeA && j < sizeB) {
        if (setA[i] < setB[j]) {
            result[k++] = setA[i++];
        } else if (setA[i] > setB[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < sizeA) {
        result[k++] = setA[i++];
    }

    if (k == 0) {
        printf("empty\n");
    } else {
        printSet(result, k);
    }
}

// Function to find the complement of a set
void complementSet(int set[], int size, int universe[], int universeSize) {
    int result[universeSize];
    int i, j;
    i = j = 0;

    while (i < size && j < universeSize) {
        if (set[i] < universe[j]) {
            result[j++] = set[i++];
        } else if (set[i] > universe[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (j < universeSize) {
        result[j++] = universe[i++];
    }

    if (j == 0) {
        printf("empty\n");
    } else {
        printSet(result, universeSize);
    }
}

int main() {
    // Read input
    int m, n, p, q;
    scanf("%d %d", &m, &n);

    int universeSize = n - m + 1;
    int universe[universeSize];
    for (int i = 0; i < universeSize; i++) {
        universe[i] = m + i;
    }

    scanf("%d", &p);
    int setA[p];
    for (int i = 0; i < p; i++) {
        scanf("%d", &setA[i]);
    }

    scanf("%d", &q);
    int setB[q];
    for (int i = 0; i < q; i++) {
        scanf("%d", &setB[i]);
    }

    // Print the sets
    printSet(setA, p);
    printSet(setB, q);

    // Perform set operations
    unionSets(setA, p, setB, q, universe, universeSize);
    intersectSets(setA, p, setB, q);
    differenceSets(setA, p, setB, q);
    differenceSets(setB, q, setA, p);
    complementSet(setA, p, universe, universeSize);
    complementSet(setB, q, universe, universeSize);

    return 0;
}
