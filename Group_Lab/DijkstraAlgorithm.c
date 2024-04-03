#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

void dijkstra(int graph[MAX_NODES][MAX_NODES], int n, int src) {
    int dist[MAX_NODES]; // To store the shortest distance from src to i
    int visited[MAX_NODES] = {0}; // Mark nodes as not visited

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u, min = INT_MAX;
        for (int v = 0; v < n; v++)
            if (!visited[v] && dist[v] <= min)
                min = dist[v], u = v;

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist[] value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
}

int main() {
    int n, src;
    scanf("%d %d", &n, &src);

    int graph[MAX_NODES][MAX_NODES];

    // Input adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    dijkstra(graph, n, src);

    return 0;
}
