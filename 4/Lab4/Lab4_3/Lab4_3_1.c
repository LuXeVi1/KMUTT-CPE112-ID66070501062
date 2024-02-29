//️️Lab 4.3 : Secret Code Only You and I Know
//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

typedef struct {
    char character;
    int priority;
} CharPriority;

int compare(const void *a, const void *b) {
    return ((CharPriority *)a)->priority - ((CharPriority *)b)->priority;
}

char* string(char *s) {
    CharPriority pq[MAX_LENGTH];
    int size = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        int priority;

        if (isalpha(c)) {
            if (strchr("aeiouAEIOU", c) != NULL)
                priority = 1;
            else
                priority = 3;
        } else if (c == ' ') {
            priority = 2;
        } else {
            priority = 2;
        }

        pq[size].character = c;
        pq[size].priority = priority;
        size++;
    }

    qsort(pq, size, sizeof(CharPriority), compare);

    char *transformed_string = (char *)malloc((size + 1) * sizeof(char));
    if (transformed_string == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
        transformed_string[index++] = pq[i].character;
    }
    transformed_string[index] = '\0';

    return transformed_string;
}

int main() {
    char input_string[MAX_LENGTH];
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    char *result = string(input_string);
    printf("%s\n", result);

    free(result);

    return 0;
}
