#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjList = malloc(vertices * sizeof(Node*));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;
    
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

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjList[v];
        printf("\n Vertex %d \n: ", v);
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
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}