/*
66070501003 Kanyaphat Chaithawip
66070501036 Ponprathan Kuearung
66070501062 Arkkhanirut Pandej
66070501068 Khunnapat Aubontara
*/

#include <stdio.h>
#include <limits.h>

#define MAX_NODES 100

void dijkstra(int graph[MAX_NODES][MAX_NODES], int nodes, int source) {
    int distance[MAX_NODES];
    int visited[MAX_NODES] = {0};

    for (int i = 0; i < nodes; i++) {
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        int min_dist = INT_MAX;
        int min_index;

        for (int j = 0; j < nodes; j++) {
            if (!visited[j] && distance[j] <= min_dist) {
                min_dist = distance[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        for (int k = 0; k < nodes; k++) {
            if (!visited[k] && graph[min_index][k] != 0 && distance[min_index] != INT_MAX &&
                distance[min_index] + graph[min_index][k] < distance[k]) {
                distance[k] = distance[min_index] + graph[min_index][k];
            }
        }
    }

    for (int i = 0; i < nodes; i++) {
        if (i != source) {
            printf("%d %d\n", i, distance[i]);
        }
    }
}

int main() {
    int nodes, source;
    scanf("%d %d", &nodes, &source);

    int graph[MAX_NODES][MAX_NODES];
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    dijkstra(graph, nodes, source);

    return 0;
}
