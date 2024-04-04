#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 1000

typedef struct Graph {
    int visited[MAX_VERTICES];
    int n, m;
    int *graph[MAX_VERTICES];
    int size[MAX_VERTICES];
} Graph;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addEdge(Graph* g, int v1, int v2) {
    g->graph[v1] = realloc(g->graph[v1], sizeof(int) * (g->size[v1] + 1));
    if (g->graph[v1] == NULL) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    g->graph[v1][g->size[v1]++] = v2;
}

void sortIntArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void bfs(Graph* g, int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    g->visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        sortIntArray(g->graph[current], g->size[current]);

        for (int i = 0; i < g->size[current]; i++) {
            int next = g->graph[current][i];
            if (!g->visited[next]) {
                queue[rear++] = next;
                g->visited[next] = 1;
            }
        }
    }

    printf("\n");
}

void dfsUtil(Graph* g, int start) {
    g->visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < g->size[start]; i++) {
        int next = g->graph[start][i];
        if (!g->visited[next]) {
            dfsUtil(g, next);
        }
    }
}

void dfs(Graph* g, int start) {
    memset(g->visited, 0, sizeof(g->visited));
    dfsUtil(g, start);
    printf("\n");
}

int main() {
    Graph g = {0};

    scanf("%d %d", &g.n, &g.m);

    for (int i = 0; i < g.m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(&g, v1, v2);
    }

    int start;
    scanf("%d", &start);

    bfs(&g, start);
    dfs(&g, start);

    return 0;
}
