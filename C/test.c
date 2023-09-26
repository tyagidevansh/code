#include "linked_list.h"
#include <stdio.h>

int main(){
    int n,data;
    Node* head = NULL;
    
    head = insert_intial(head);
    head = insert_beg(head, 5);
    head = insert_end(head, -1);

    print_list(head);

    printf("Enter the number of elements you want to enter: ");
    scanf("%d", &n);

    while (n>0){
        printf("Enter the element: ");
        scanf("%d", &data);
        head = insert_end(head, data);
        n--;
    }
    print_list(head);
    return 0;
}