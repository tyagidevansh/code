#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    int* visited;
    Node** adjList;
} Graph;

void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjList[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjList = (Node**)malloc(vertices*sizeof(Node*));
    graph->visited = (int*)malloc(vertices*sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int s, int d) {
    Node* newNode = createNode(d);
    newNode->next = graph->adjList[s];
    graph->adjList[s] = newNode;

    newNode = createNode(s);
    newNode->next = graph->adjList[d];
    graph->adjList[d] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Adjacency list of vertex %d \n", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);

    return 0;
}