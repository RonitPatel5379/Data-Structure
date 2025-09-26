#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int numVertices;
    struct AdjList* array;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int n) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = n;

    graph->array = (struct AdjList*)malloc(n * sizeof(struct AdjList));
    for (int i = 0; i < n; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct Node* temp = graph->array[v].head;
        printf("Adjacency list of vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void DFSUtil(int v, int visited[], struct Graph* graph) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->array[v].head;
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFSUtil(adjVertex, visited, graph);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    printf("DFS starting from vertex %d: ", startVertex);
    DFSUtil(startVertex, visited, graph);
    printf("\n");
    free(visited);
}

void BFS(struct Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    printf("BFS starting from vertex %d: ", startVertex);

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");

    free(queue);
    free(visited);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    DFS(graph, 0);
    BFS(graph, 0);

    return 0;
}