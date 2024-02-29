#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Include for isalpha()

struct CharPriority {
    char character;
    int priority;
};

int compare(const void *a, const void *b) {
    return ((struct CharPriority *)a)->priority - ((struct CharPriority *)b)->priority;
}

char* string(char *s) {

    struct CharPriority pq[strlen(s)];
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

    qsort(pq, size, sizeof(struct CharPriority), compare);

    char *transformed_string = (char *)malloc((size + 1) * sizeof(char));
    int index = 0;
    for (int i = 0; i < size; i++) {
        transformed_string[index++] = pq[i].character;
    }
    transformed_string[index] = '\0';

    return transformed_string;
}

int main() {
    char input_string[1001];
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0'; // Remove trailing newline

    char *result = string(input_string);
    printf("%s", result); // Added formatting string specifier

    // Free dynamically allocated memory
    free(result);

    return 0;
}
