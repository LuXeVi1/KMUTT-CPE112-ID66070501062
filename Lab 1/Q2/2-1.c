#include <stdio.h>
#include <stdlib.h>

// Function to print elements of a set
void printSet(int *set, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

// Function to perform union operation on two sets
int *unionSets(int *setA, int sizeA, int *setB, int sizeB, int *resultSize) {
    int *result = (int *)malloc(sizeof(int) * (sizeA + sizeB));
    int i = 0, j = 0, k = 0;

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

    *resultSize = k;
    return result;
}

// Function to perform intersection operation on two sets
int *intersectionSets(int *setA, int sizeA, int *setB, int sizeB, int *resultSize) {
    int *result = (int *)malloc(sizeof(int) * (sizeA < sizeB ? sizeA : sizeB));
    int i = 0, j = 0, k = 0;

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

    *resultSize = k;
    return result;
}

// Function to perform set difference operation (A - B) on two sets
int *differenceSets(int *setA, int sizeA, int *setB, int sizeB, int *resultSize) {
    int *result = (int *)malloc(sizeof(int) * sizeA);
    int i = 0, j = 0, k = 0;

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

    *resultSize = k;
    return result;
}

// Function to compute the complement of a set in the given universe
int *complementSet(int *universe, int universeSize, int *set, int setSize, int *resultSize) {
    int *result = (int *)malloc(sizeof(int) * (universe[universeSize - 1] - universe[0] + 1 - setSize));
    int i = 0, j = 0, k = 0;

    while (i < universeSize && j < setSize) {
        if (universe[i] < set[j]) {
            result[k++] = universe[i++];
        } else if (universe[i] > set[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    while (i < universeSize) {
        result[k++] = universe[i++];
    }

    *resultSize = k;
    return result;
}

int main() {
    int m, n, p, q, i;

    // Read the range of the universe
    scanf("%d %d", &m, &n);

    // Read array A
    scanf("%d", &p);
    int *arrA = (int *)malloc(sizeof(int) * p);
    for (i = 0; i < p; i++) {
        scanf("%d", &arrA[i]);
    }

    // Read array B
    scanf("%d", &q);
    int *arrB = (int *)malloc(sizeof(int) * q);
    for (i = 0; i < q; i++) {
        scanf("%d", &arrB[i]);
    }

    // Convert arrays A and B into sets
    int *setA = unionSets(arrA, p, arrA, p, &p);
    int *setB = unionSets(arrB, q, arrB, q, &q);

    // Perform operations
    int *resultUnion = unionSets(setA, p, setB, q, &i);
    int *resultIntersection = intersectionSets(setA, p, setB, q, &i);
    int *resultDifferenceAB = differenceSets(setA, p, setB, q, &i);
    int *resultDifferenceBA = differenceSets(setB, q, setA, p, &i);
    int *resultComplementA = complementSet(arrA, p, setA, p, &i);
    int *resultComplementB = complementSet(arrB, q, setB, q, &i);

    // Print results
    printSet(setA, p);
    printSet(setB, q);
    printSet(resultUnion, i);
    printSet(resultIntersection, i);
    printSet(resultDifferenceAB, i);
    printSet(resultDifferenceBA, i);
    printSet(resultComplementA, i);
    printSet(resultComplementB, i);

    // Free allocated memory
    free(arrA);
    free(arrB);
    free(setA);
    free(setB);
    free(resultUnion);
    free(resultIntersection);
    free(resultDifferenceAB);
    free(resultDifferenceBA);
    free(resultComplementA);
    free(resultComplementB);

    return 0;
}
