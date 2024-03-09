// Arkkhanirut Pandej 66070501005
#include <stdio.h>


void removeDuplicatesAndSort(int *set, int *size) {
    int index = 0;

    for (int i = 0; i < *size; i++) {
        if (i == 0 || set[i] != set[i - 1]) {
            set[index++] = set[i];
        }
    }
    *size = index;
}

void filterWithinRange(int *set, int *size, int m, int n) {
    int index = 0;

    for (int i = 0; i < *size; i++) {
        if (set[i] >= m && set[i] <= n) {
            set[index++] = set[i];
        }
    }
    *size = index;
}

void unionSets(int setA[], int setB[], int sizeA, int sizeB) {
    int result[sizeA + sizeB];
    int sizeResult = 0;

    for (int i = 0, j = 0; i < sizeA || j < sizeB;) {
        if (i < sizeA && (j >= sizeB || setA[i] < setB[j])) {
            result[sizeResult++] = setA[i++];
        } else if (j < sizeB && (i >= sizeA || setA[i] > setB[j])) {
            result[sizeResult++] = setB[j++];
        } else {
            result[sizeResult++] = setA[i++];
            j++;
        }
    }

    for (int i = 0; i < sizeResult; i++) {
        printf("%d ", result[i]);
    }
    if (sizeResult == 0) {
        printf("empty");
    }
}

void intersectSets(int setA[], int setB[], int sizeA, int sizeB) {
    int result[sizeA + sizeB];
    int sizeResult = 0;

    for (int i = 0, j = 0; i < sizeA && j < sizeB;) {
        if (setA[i] < setB[j]) {
            i++;
        } else if (setA[i] > setB[j]) {
            j++;
        } else {
            result[sizeResult++] = setA[i++];
            j++;
        }
    }

    for (int i = 0; i < sizeResult; i++) {
        printf("%d ", result[i]);
    }
    if (sizeResult == 0) {
        printf("empty");
    }
}

void setDifference(int setA[], int setB[], int sizeA, int sizeB) {
    int result[sizeA];
    int sizeResult = 0;

    for (int i = 0; i < sizeA; i++) {
        int found = 0;
        for (int j = 0; j < sizeB; j++) {
            if (setA[i] == setB[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            result[sizeResult++] = setA[i];
        }
    }

    for (int i = 0; i < sizeResult; i++) {
        printf("%d ", result[i]);
    }
    if (sizeResult == 0) {
        printf("empty");
    }
}

void setComplement(int set[], int size, int m, int n) {
    int index = 0;

    for (int i = m; i <= n; i++) {
        if (index < size && set[index] == i) {
            index++;
        } else {
            printf("%d ", i);
        }
    }

    if (size == n - m + 1) {
        printf("empty");
    }
}

int main() {
    int m, n, sizeA, sizeB;
    scanf("%d %d", &m, &n);
    scanf("%d", &sizeA);

    int setA[sizeA];
    for (int i = 0; i < sizeA; i++) {
        scanf("%d", &setA[i]);
    }

    removeDuplicatesAndSort(setA, &sizeA);
    filterWithinRange(setA, &sizeA, m, n);

    scanf("%d", &sizeB);
    int setB[sizeB];

    for (int i = 0; i < sizeB; i++) {
        scanf("%d", &setB[i]);
    }

    removeDuplicatesAndSort(setB, &sizeB);
    filterWithinRange(setB, &sizeB, m, n);

    // Print the sets
    for (int i = 0; i < sizeA; i++) {
        printf("%d ", setA[i]);
    }

    if (sizeA == 0) {
        printf("empty");
    }

    printf("\n");

    for (int i = 0; i < sizeB; i++) {
        printf("%d ", setB[i]);
    }

    if (sizeB == 0) {
        printf("empty");
    }

    printf("\n");

    // Perform set operations
    unionSets(setA, setB, sizeA, sizeB);
    printf("\n");

    intersectSets(setA, setB, sizeA, sizeB);
    printf("\n");

    setDifference(setA, setB, sizeA, sizeB);
    printf("\n");

    setDifference(setB, setA, sizeB, sizeA);
    printf("\n");

    setComplement(setA, sizeA, m, n);
    printf("\n");

    setComplement(setB, sizeB, m, n);

    return 0;
}
