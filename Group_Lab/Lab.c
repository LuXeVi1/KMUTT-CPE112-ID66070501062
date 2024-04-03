#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

// Create a graph with the given vertices and edges
void create_graph(int vertices, int edges) {
    int i, u, v, j;

    // Initialize the graph as an empty graph
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    // Read edges and add them to the graph
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming undirected graph
    }
}

// Perform BFS traversal
void BFS(int start) {
    int queue[MAX_VERTICES], front = 0, rear = -1;

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        // Visit unvisited neighbors of the current vertex
        for (int i = 0; i < MAX_VERTICES; i++) {
            if (graph[vertex][i] &&!visited[i]) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

// Perform DFS traversal using recursion
void DFS_recursive(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Visit unvisited neighbors of the current vertex
    for (int i = 0; i < MAX_VERTICES; i++) {
        if (graph[vertex][i] &&!visited[i]) {
            DFS_recursive(i);
        }
    }
}

// Perform DFS traversal
void DFS(int start) {
    int i;

    // Reset the visited array
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }

    // Perform DFS traversal starting from the initial vertex
    DFS_recursive(start);
}

int main() {
    int vertices, edges, start;

    // Read the number of vertices and edges
    scanf("%d %d", &vertices, &edges);

    // Create the graph
    create_graph(vertices, edges);

    // Read the initial vertex
    scanf("%d", &start);

    // Perform BFS and DFS traversals
    BFS(start);
    printf("\n");

    DFS(start);
    printf("\n");

    return 0;
}