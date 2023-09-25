#include "linked_list.h"
#include <stdio.h>

int main(){

    Node* head = NULL;

    head = insert_intial(head);
    head = insert_beg(head, 5);
    head = insert_end(head, -1);
    head = insert_between(head, 4, 4);
    head = delete_beg(head);
    //head = delete_end(head);
    //head = delete_val(head, 0);
    head = delete_pos(head, 3);
    //head = reverse_iter(head);
    head = reverse_recur(head);
    print_list(head);

    return 0;
}