/*
66070501003 Kanyaphat Chaithawip
66070501036 Ponprathan Kuearung
66070501062 Arkkhanirut Pandej
66070501068 Khunnapat Aubontara
*/

#include <stdio.h>

#define MAX_NODES 100
#define INFINITY 999999

void displayDistances(int distances[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, distances[i]);
    }
}

int minDistance(int distances[], int visited[], int n) {
    int min = INFINITY, minIndex;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && distances[v] <= min) {
            min = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void Dijkstra(int adjMatrix[][MAX_NODES], int nodes, int source) {
    int distances[nodes];
    int visited[nodes];

    for (int i = 0; i < nodes; i++) {
        distances[i] = INFINITY;
        visited[i] = 0;
    }

    distances[source] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        int k = minDistance(distances, visited, nodes);
        visited[k] = 1;
        
        for (int j = 0; j < nodes; j++) {
            if (!visited[j] && adjMatrix[k][j] && distances[k] != INFINITY &&
                distances[k] + adjMatrix[k][j] < distances[j]) {
                distances[j] = distances[k] + adjMatrix[k][j];
            }
        }
    }

    displayDistances(distances, nodes);
}

int main() {
    int nodes, source;
    scanf("%d %d", &nodes, &source);

    if (nodes < 1 || nodes > MAX_NODES || source < 0 || source >= nodes) {
        printf("Invalid input.\n");
        return 1;
    }

    int adjMatrix[nodes][MAX_NODES];
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    Dijkstra(adjMatrix, nodes, source);

    return 0;
}
