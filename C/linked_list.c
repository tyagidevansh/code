#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void print_list(Node* head);
Node* insert_intial(Node* head);
Node* insert_beg(Node* head, int data);

int main(){

    Node* head = NULL;

    //head = insert_intial(head);
    head = insert_beg(head, 1);
    print_list(head);

    return 0;
}

void print_list(Node* head){
    Node* current = head;
    while (current != NULL){
        printf("%d ", current -> data );
        current = current -> next;
    }
    printf("\n");
}

Node* insert_intial(Node* head){
    for (int i = 0; i < 5; i++){
        Node* new;
        new = (Node*)malloc(sizeof(Node));
        if (new == NULL){
            printf("Memory allocation failed");
            break;
        }

        new -> data = i;
        new -> next = head;
        head = new;
    }
    return head;
}

Node* insert_beg(Node *head, int data) {
    Node* new;

    new = (Node*)malloc(sizeof(Node));
    
    if (new == NULL) {
        printf("Memory allocation failed\n");
        return head;
    }

    new->data = data;
    new->next = head;
    head = new;
    return head;
}

Node* insert_end(Node* head, int data){
    Node *new;

    new = (Node*)malloc(sizeof(Node));

    if (new == NULL){
        printf("Memory allocation failed");
        return head;
    }
}