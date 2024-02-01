//Assignment 2.1 : Grading
// Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <math.h>
#include <string.h>

struct Student {
    char name[101];
    float score;
};

int main() {
    int size;
    // printf("Enter the number of students: ");
    scanf("%d", &size);

    struct Student students[size];
    float sum = 0, mean, variance = 0, sd;
    float max_score = -1, min_score = 101;
    char max_name[101], min_name[101];

    // Input
    for (int i = 0; i < size; i++) {
        // printf("Enter name and score for student %d: ", i+1);
        scanf("%s %f", students[i].name, &students[i].score);

        // Calculate sum
        sum += students[i].score;

        // Calculate max and min
        if (students[i].score > max_score) {
            max_score = students[i].score;
            strcpy(max_name, students[i].name);
        }
        if (students[i].score < min_score) {
            min_score = students[i].score;
            strcpy(min_name, students[i].name);
        }
    }

    // Calculate mean
    mean = sum / size;

    // Calculate variance
    for (int i = 0; i < size; i++) {
        variance += pow(students[i].score - mean, 2);
    }
    variance /= size;

    // Calculate standard deviation
    sd = sqrt(variance);

    // Output
    // printf("Mean: %.2f, Standard Deviation: %.2f\n", mean, sd);
    // printf("Student with maximum score: %s\n", max_name);
    // printf("Student with minimum score: %s\n", min_name);

    // Output
    printf("%.2f ", mean);
    printf("%.2f ", sd);
    printf("%s ", max_name);
    printf("%s", min_name);


    return 0;
}