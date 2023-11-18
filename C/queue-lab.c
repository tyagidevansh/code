#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;
    Node* rear;
}Queue;

void init(Queue* queue){
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue){
    return (queue -> front == NULL);
}

void enqueue(Queue** queue, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(*queue)){
        (*queue)->front = (*queue)->rear = newNode;
    } else {
        (*queue)->rear->next = newNode;
        (*queue)->rear = newNode;
    }

    printf("%d enqueued \n", data);
}

void dequeue(Queue** queue){
    if (isEmpty(*queue)){
        printf("Queue is empty! No elements can be dequeued. \n");
        return;
    }
    
    Node* temp = (*queue)->front;
    (*queue)->front = (*queue)->front->next;

    if ((*queue)->front == NULL){
        (*queue)->rear = NULL;
    }

    printf("%d dequeued \n", temp->data);
    free(temp);
}

void display(Queue* queue){
    Node* temp = queue->front;
    printf("All the elements in the queue: ");
    while(temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    init(queue);
    enqueue(&queue, 5); 
    enqueue(&queue, 15); 
    enqueue(&queue, 52); 
    enqueue(&queue, 53); 
    display(queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    display(queue);
}