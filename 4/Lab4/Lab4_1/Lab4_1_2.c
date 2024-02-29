#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
    char name[50];
    char artist[50];
    int time;
    struct song* next;
} Song;

typedef struct queue {
    Song* front;
    Song* rear;
} Queue;

Song* newSong(char* name, char* artist, int time) {
    Song* temp = (Song*)malloc(sizeof(Song));
    strcpy(temp->name, name);
    strcpy(temp->artist, artist);
    temp->time = time;
    temp->next = NULL;
    return temp;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue* q, char* name, char* artist, int time) {
    Song* temp = newSong(name, artist, time);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void deQueue(Queue* q) {
    if (q->front == NULL)
        return;
    Song* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    printf("Now playing: %s by %s\n", temp->name, temp->artist);
    free(temp);
}

void displayQueue(Queue* q) {
    if(q->front == NULL) {
        printf("No songs in the playlist\n");
        return;
    }
    Song* temp = q->front;
    int total = 0;
    printf("Songs in the playlist:\n");
    while(temp != NULL) {
        printf("%s by %s %dsec\n", temp->name, temp->artist, temp->time);
        total += temp->time;
        temp = temp->next;
    }
    printf("Remaining Time: %dsec\n", total);
}

int main() {
    Queue* q = createQueue();
    char command[50], name[50], artist[50];
    int time;
    while(scanf("%s", command) != EOF) {
        if(strcmp(command, "add") == 0) {
            scanf("%s", name);
            scanf("%s", artist);
            scanf("%d", &time);
            enQueue(q, name, artist, time);
        } else if(strcmp(command, "play") == 0) {
            deQueue(q);
        } else if(strcmp(command, "sum") == 0) {
            displayQueue(q);
        }
    }
    return 0;
}