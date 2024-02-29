//Lab 4.1: Spotify
//Arkkhanirut Pandej 66070501062

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QNode {
    char song[50];
    char artist[50];
    int time;
    struct QNode* next;
} QNode;

struct Queue {
    QNode *front, *rear;
};

struct Queue* createQueue(){
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

QNode *newNode(char *song_name, char *artist_name, int time) {
	struct QNode *temp = (struct QNode*)malloc(sizeof(struct QNode));
    strcpy(temp->song, song_name);
    strcpy(temp->artist, artist_name);
    temp->time = time;
	temp->next = NULL;
	return temp;
}

// enqueue
void add(struct Queue *q, char *song_name, char *artist_name, int time){
    QNode* temp = newNode(song_name, artist_name, time);

    if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}
    q->rear->next = temp;   // add new node at the end of the queue and change rear
	q->rear = temp;

}

// dequeue
void play(struct Queue* q){
    if (q->front == NULL){
        printf("No songs in the playlist\n");
        return;
    }
    printf("Now playing: %s by %s\n", q->front->song, q->front->artist);

    QNode* temp = q->front;

	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}

void sum(struct Queue* q){
    if (q->front == NULL){
        printf("No songs in the playlist\n");
        return;
    }

    printf("Songs in the playlist:\n");
    int TIME = 0;
    while (q->front != NULL)
    {
        TIME += q->front->time;
        printf("%s by %s %d\n", q->front->song, q->front->artist, q->front->time);

        // dequeue
        QNode* temp = q->front;
        q->front = q->front->next;

	    if (q->front == NULL)
		    q->rear = NULL;

	    free(temp);
    }
    
    printf("Remaining Time: %d\n", TIME);
}

int main(){
    struct Queue* q = createQueue();

    while (1)
    {
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            char song_name[50], artist_name[50];
            int time;
            getchar(); // Clear the newline character from the input buffer
            fgets(song_name, sizeof(song_name), stdin);
            song_name[strcspn(song_name, "\n")] = '\0'; // Remove trailing newline
            
            fgets(artist_name, sizeof(artist_name), stdin);
            artist_name[strcspn(artist_name, "\n")] = '\0'; // Remove trailing newline
         
            scanf("%d", &time);
            add(q, song_name, artist_name, time);
        }
        else if (strcmp(input, "play") == 0) {
            play(q);
        }
        else if (strcmp(input, "sum") == 0) {
            sum(q);
            return 0;
        }
    }
    
    return 0;
    
}