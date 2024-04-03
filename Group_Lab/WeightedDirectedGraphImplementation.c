/*
66070501003 Kanyaphat Chaithawip
66070501036 Ponprathan Kuearung
66070501062 Arkkhanirut Pandej
66070501068 Khunnapat Aubontara
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList; 
};

struct Node* createNode(int dest, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (!graph) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    if (!graph->adjList) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    struct Node** current = &(graph->adjList[src]);
    while (*current != NULL && ((*current)->dest < dest || ((*current)->dest == dest && (*current)->weight < weight))) {
        current = &((*current)->next);
    }
    newNode->next = *current;
    *current = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            printf("%d -> %d (%d)\n", i, temp->dest, temp->weight);
            temp = temp->next;
        }
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjList[i];
        while (temp != NULL) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjList);
    free(graph);
}

int main() {
    int totalLines;
    scanf("%d", &totalLines);

    struct Graph* graph = createGraph(totalLines + 1);

    int src, dest, weight;
    for (int i = 0; i < totalLines; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    printGraph(graph);

    freeGraph(graph);

    return 0;
}