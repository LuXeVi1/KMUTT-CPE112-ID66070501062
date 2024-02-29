#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Structure to represent a song
struct Song {
    char name[MAX_LENGTH];
    char artist[MAX_LENGTH];
    int time;
    struct Song* next;
};

// Structure to represent the playlist (queue)
struct Playlist {
    struct Song* front;
    struct Song* rear;
    int total_time;
};

// Function prototypes
void initializePlaylist(struct Playlist* playlist);
void addSong(struct Playlist* playlist);
void playSong(struct Playlist* playlist);
void displayPlaylist(struct Playlist* playlist);

int main() {
    struct Playlist playlist;
    char command[MAX_LENGTH];

    initializePlaylist(&playlist);

    while (1) {
        printf("Enter command (add, play, sum): ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "add", 3) == 0) {
            addSong(&playlist);
        } else if (strncmp(command, "play", 4) == 0) {
            playSong(&playlist);
        } else if (strncmp(command, "sum", 3) == 0) {
            displayPlaylist(&playlist);
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}

// Function to initialize the playlist
void initializePlaylist(struct Playlist* playlist) {
    playlist->front = NULL;
    playlist->rear = NULL;
    playlist->total_time = 0;
}

// Function to add a song to the playlist (enqueue)
void addSong(struct Playlist* playlist) {
    struct Song* newSong = (struct Song*)malloc(sizeof(struct Song));
    printf("Enter song name: ");
    fgets(newSong->name, sizeof(newSong->name), stdin);
    printf("Enter artist: ");
    fgets(newSong->artist, sizeof(newSong->artist), stdin);
    printf("Enter time (in seconds): ");
    scanf("%d", &newSong->time);
    getchar(); // consume '\n' left by scanf

    newSong->next = NULL;

    if (playlist->rear == NULL) {
        playlist->front = newSong;
    } else {
        playlist->rear->next = newSong;
    }
    playlist->rear = newSong;
    playlist->total_time += newSong->time;
}

// Function to play a song from the playlist (dequeue)
void playSong(struct Playlist* playlist) {
    if (playlist->front == NULL) {
        printf("No songs in the playlist\n");
    } else {
        struct Song* temp = playlist->front;
        playlist->front = playlist->front->next;
        playlist->total_time -= temp->time;
        printf("Now playing: %s by %s\n", temp->name, temp->artist);
        free(temp);
    }
}

// Function to display all songs in the playlist and remaining time
void displayPlaylist(struct Playlist* playlist) {
    if (playlist->front == NULL) {
        printf("No songs in the playlist\n");
    } else {
        printf("Songs in the playlist:\n");
        struct Song* current = playlist->front;
        while (current != NULL) {
            printf("%s by %s %dsec\n", current->name, current->artist, current->time);
            current = current->next;
        }
        printf("Remaining Time: %d\n", playlist->total_time);
    }
}
