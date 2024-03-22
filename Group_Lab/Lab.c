#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct node {
    int vertex;
    struct node* next;
} node;

node* createNode(int v);
void addEdge(node* adjList[], int src, int dest);
void printGraph(node* adjList[], int vertices);
void BFS(node* adjList[], int startVertex, int vertices);
void DFS(node* adjList[], int startVertex, int visited[]);

int main() {
    int vertices, edges, i, src, dest, startVertex;

    scanf("%d", &vertices);
    node* adjList[vertices];
    for (i = 0; i < vertices; i++) {
        adjList[i] = NULL;
    }

    scanf("%d", &edges);
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(adjList, src, dest);
    }

    scanf("%d", &startVertex);
    BFS(adjList, startVertex, vertices);
    printf("\n");

    int visited[vertices];
    for (i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    DFS(adjList, startVertex, visited);

    return 0;
}

node* createNode(int v) {
    node* newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(node* adjList[], int src, int dest) {
    node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void BFS(node* adjList[], int startVertex, int vertices) {
    int visited[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }

    int queue[MAX];
    int front = -1;
    int rear = -1;

    queue[++rear] = startVertex;
    visited[startVertex] = 1;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);

        node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (visited[adjVertex] == 0) {
                queue[++rear] = adjVertex;
                visited[adjVertex] = 1;
            }
            temp = temp->next;
        }
    }
}

void DFS(node* adjList[], int startVertex, int visited[]) {
    printf("\n");
    visited[startVertex] = 1;
    printf("%d ", startVertex);

    node* temp = adjList[startVertex];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (visited[connectedVertex] == 0) {
            DFS(adjList, connectedVertex, visited);
        }
        temp = temp->next;
    }
}