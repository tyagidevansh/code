#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void insert_end(Node** head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

Node* insert_front(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    Node* next = head;
    head = newNode;
    newNode->next = next;
    return head;
}

void printlist(Node* head){
    while (head -> next != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main(){
    Node* head = NULL;
    insert_end(&head, 5);
    insert_end(&head, 10);
    head = insert_front(head, 1);
    head = insert_front(head, 3);
    printlist(head);
    return 0;
}