#include "linked_list.h"
#include <stdio.h>

int main(){

    Node* head = NULL;

    for (int i = 0; i<10;i++){
            head = insert_end(head,i);
    }

    print_list(head);

    return 0;
}