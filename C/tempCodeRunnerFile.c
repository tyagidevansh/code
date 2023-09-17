#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

int main(){

    Node* head = NULL;

    for (int i = 4; i >= 0; i--){
        Node *newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL){
            printf("Memory allocation failed");
            return 1;
        }

        newNode->data = i;
        newNode->next = head;

        head = newNode;
    }

    Node* current = head;
    while (current != NULL) {
        printf("%d ", current -> data);
        current = current -> next;
    }

    printf("NULL \n");

    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current -> next;
        free(temp);
    }    

    return 0;
}