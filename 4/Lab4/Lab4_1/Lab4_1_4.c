#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
    char song[50];
    char artist[50];
    int time;
    struct QNode* next;
} QNode;

typedef struct Queue {
    QNode *front, *rear;
} Queue;

Queue* createQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

QNode* newNode(const char *song_name, const char *artist_name, int time) {
    QNode *temp = (QNode*)malloc(sizeof(QNode));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    strcpy(temp->song, song_name);
    strcpy(temp->artist, artist_name);
    temp->time = time;
    temp->next = NULL;
    return temp;
}

void add(Queue *q, const char *song_name, const char *artist_name, int time){
    QNode* temp = newNode(song_name, artist_name, time);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void play(Queue* q){
    if (q->front == NULL){
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s by %s\n", q->front->song, q->front->artist);
    QNode* temp = q->front;
    q->front = q->front->next;
    free(temp);
    if (q->front == NULL)
        q->rear = NULL;
}

void sum(Queue* q){
    if (q->front == NULL){
        printf("No songs in the playlist\n");
        return;
    }
    printf("Songs in the playlist:\n");
    int TIME = 0;
    QNode* current = q->front;
    while (current != NULL) {
        printf("%s by %s %d\n", current->song, current->artist, current->time);
        TIME += current->time;
        current = current->next;
    }
    printf("Remaining Time: %d\n", TIME);
}

void cleanup(Queue *q) {
    while (q->front != NULL) {
        QNode *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }
    q->rear = NULL;
    free(q);
}

int main(){
    Queue* q = createQueue();

    while (1) {
        char input[10];
        // printf("Enter command (add, play, sum): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char song_name[50], artist_name[50];
            int time;
            getchar(); // Clear the newline character from the input buffer
            // printf("Enter song name: ");
            fgets(song_name, sizeof(song_name), stdin);
            song_name[strcspn(song_name, "\n")] = '\0'; // Remove trailing newline
            
            // printf("Enter artist name: ");
            fgets(artist_name, sizeof(artist_name), stdin);
            artist_name[strcspn(artist_name, "\n")] = '\0'; // Remove trailing newline
         
            // printf("Enter song duration (in seconds): ");
            scanf("%d", &time);
            add(q, song_name, artist_name, time);
        }
        else if (strcmp(input, "play") == 0) {
            play(q);
        }
        else if (strcmp(input, "sum") == 0) {
            sum(q);
            cleanup(q); // Free allocated memory before exiting
            return 0;
        }
        else {
            printf("Invalid command\n");
        }
    }
    return 0;
}
