#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Song {
    char name[100];
    char artist[100];
    int time;
};

struct Node {
    struct Song data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(char name[], char artist[], int time) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data.name, name);
    strcpy(newNode->data.artist, artist);
    newNode->data.time = time;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("No songs in the playlist\n");
        return 0;
    }
    
    struct Node* temp = front;
    front = front->next;
    
    printf("Now playing: %s by %s\n", temp->data.name, temp->data.artist);
    free(temp);
    return 1;
}

int displayQueue() {
    if (front == NULL) {
        printf("No songs in the playlist\n");
        return 0;
    }
    
    struct Node* temp = front;
    int totalRemainingTime = 0;
    
    printf("Songs in the playlist:\n");
    while (temp != NULL) {
        printf("%s by %s %dsec\n", temp->data.name, temp->data.artist, temp->data.time);
        totalRemainingTime += temp->data.time;
        temp = temp->next;
    }
    
    printf("Remaining time: %d\n", totalRemainingTime);
    return 1;
}

int main() {
    char input[10];
    char name[100];
    char artist[100];
    int time;
    
    while (1) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = 0;
            scanf("%d", &time);
            enqueue(name, artist, time);
        } else if (strcmp(input, "play") == 0) {
            if (!dequeue()) {
                break;
            }
        } else if (strcmp(input, "sum") == 0) {
            if (!displayQueue()) {
                break;
            }
        } else {
            break;
        }
    }

    return 0;
}