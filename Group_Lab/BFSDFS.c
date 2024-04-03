#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_VERTICES 1000

int visited[MAX_VERTICES];
int n, m;
int *graph[MAX_VERTICES];
int size[MAX_VERTICES];

void addEdge(int v1, int v2) {
    graph[v1] = realloc(graph[v1], sizeof(int) * (size[v1] + 1));
    graph[v1][size[v1]++] = v2;
}


void sortIntArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bfs(int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        // Sort the neighbors before traversing
        sortIntArray(graph[current], size[current]);

        for (int i = 0; i < size[current]; i++) {
            int next = graph[current][i];
            if (!visited[next]) {
                queue[rear++] = next;
                visited[next] = 1;
            }
        }
    }

    printf("\n");
}


void dfsUtil(int start) {
    visited[start] = 1;
    printf("%d ", start);

    for (int i = 0; i < size[start]; i++) {
        int next = graph[start][i];
        if (!visited[next]) {
            dfsUtil(next);
        }
    }
}

void dfs(int start) {
    memset(visited, 0, sizeof(visited));
    dfsUtil(start);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        addEdge(v1, v2);
        addEdge(v2, v1); // assuming undirected graph
    }

    int start;
    scanf("%d", &start);

    bfs(start);
    dfs(start);
    
    return 0;
}
