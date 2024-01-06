#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct Queue {
    int list[SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}