#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void print_list(Node* head);
Node* insert_intial(Node* head);
Node* insert_beg(Node* head, int data);
Node* insert_end(Node* head, int data);
Node* insert_between(Node* head, int data, int pos);
Node* delete_beg(Node* head);
Node* delete_end(Node* head);
Node* delete_val(Node* head, int x);
Node* delete_pos(Node* head, int pos);
Node* reverse_iter(Node* head);
Node* reverse_recur(Node* head);

// int main(){

//     Node* head = NULL;

//     head = insert_intial(head);
//     head = insert_beg(head, 5);
//     head = insert_end(head, -1);
//     head = insert_between(head, 4, 4);
//     head = delete_beg(head);
//     //head = delete_end(head);
//     //head = delete_val(head, 0);
//     head = delete_pos(head, 3);
//     //head = reverse_iter(head);
//     head = reverse_recur(head);
//     print_list(head);

//     return 0;
// }

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

    new -> data = data;
    new -> next = NULL;
    Node* ptr = head;
    while (ptr -> next != NULL){
        ptr = ptr -> next;
    }
    ptr -> next = new;
    return head;
}

Node* insert_between(Node* head, int data, int pos){

    Node* new;
    new = (Node*)malloc(sizeof(Node));

    if (new == NULL){
        printf("Memory allocation failed");
        return head;
    }
    
    Node *ptr = head;

    for (int i = 0; i < pos-1; i++){
        if (ptr -> next == NULL){
            printf("Position exceeds the length of the list.");
            free (new);
            return head;
        }
        ptr = ptr -> next;
    }
    
    new -> data = data;
    new -> next = ptr -> next;
    ptr -> next = new;
    return head;
}

Node* delete_beg(Node* head){
    Node* ptr;
    if (head == NULL){
        printf("The list is empty");
    }
    else{
        ptr = head;
        head = head -> next;
        free(ptr);
    }
    return head;
}

Node* delete_end(Node* head){
    Node* ptr,*prev;

    if (head == NULL){
        printf("List is empty");
    }
    else if(head -> next == NULL){
        free (head);
        head = NULL;
    }
    else{
        ptr = head;
        while (ptr -> next != NULL){
            prev = ptr;
            ptr = ptr -> next;
        }
        prev -> next = NULL;
        free (ptr);
    }
    return head;
}

Node* delete_val(Node* head, int x){
    Node* ptr = head;
    Node* prev = NULL;

    while (ptr != NULL){
        if (ptr -> data == x){
            if (prev == NULL){ //is the node to be deleted the head?
                head = ptr -> next;
            }
            else{
                prev -> next = ptr -> next;
            }
            free(ptr);
            return head;
        }
        prev = ptr;
        ptr = ptr -> next;
    }
    printf("Value to be deleted not found in the list");
    return head;
}

Node* delete_pos(Node* head, int pos){
    Node* ptr = head;
    Node* prev = NULL;

    for (int i = 0; i < pos;i++){
        if (ptr -> next == NULL){
            printf("This index value exceeds the length of the list");
            free (ptr);
            return head;
        }
        prev = ptr;
        ptr = ptr -> next;
    }    
    prev -> next = ptr -> next;
    free(ptr);
    return head;
}

Node* reverse_iter(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr){
        next = curr-> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* reverse_recur(Node* head){
    if (head == NULL || head -> next == NULL){
        return head; //if list is empty or has only one element
    }

    Node *rev = reverse_recur(head-> next);

    head -> next -> next = head;
    head -> next = NULL;

    return rev;
}
