#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert_end(Node* head, int data) {
    Node* new = (Node*)malloc(sizeof(Node));

    if (new == NULL) {
        printf("Memory allocation failed");
        return head;
    }

    new->data = data;
    new->next = NULL;

    if (head == NULL) {
        head = new;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new;
    }

    return head;
}

void print_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node* insert(Node* head) {
    int data;
    bool isValid = true;

    while (isValid) {
        printf("Enter an element: ");
        isValid = (scanf("%d", &data) == 1);

        if (isValid) {
            head = insert_end(head, data);
        }
        else return head;
    }
    return head;
}

int main() {
    Node* head = NULL;

    head = insert(head);

    print_list(head);

    return 0;
}
