#ifndef LINKED_LIST_H
#define LINKED_LIST_H

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

#endif