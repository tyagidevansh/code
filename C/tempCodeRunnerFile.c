//circular doubly linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode (int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

Node* initList(int data) {
    Node* head = createNode(data);
    head->next = head->prev = head;
    return head;
}

Node* insert_beg(Node* head, int data) {
    Node* newNode = createNode(data);
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    head->prev = newNode;
    newNode->next = head;
    newNode->prev = temp;
    head = newNode;
    return head;
}

void traverse(Node* head) {
    Node* temp = head;
    while (temp-> next != head) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = initList(5);
    head = insert_beg(head, 10);
    head = insert_beg(head, 15);
    head = insert_beg(head, 16);
    head = insert_beg(head, 17);
    traverse(head);
}