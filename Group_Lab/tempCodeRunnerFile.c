// Perform BFS traversal
void bfs(int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        // Sort the adjacency list of the current vertex
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