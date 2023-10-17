#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** last, int data) {
    Node* newNode = createNode(data);

    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void delete(Node** last, int data) {
    if (*last == NULL) {
        printf("List empty!\n");
        return;
    }

    Node* first = (*last)->next;
    Node* temp = first;
    Node* prev = *last;

    do {
        if (temp->data == data) {
            prev->next = temp->next;
            if (temp == first) {
                if (temp->next == temp) {
                    *last = NULL;
                } else {
                    (*last)->next = temp->next;
                    first = temp->next;
                }
            }
            free(temp);
            printf("%d deleted \n", data);
            return;
        } else {
            prev = temp;
            temp = temp->next;
        }
    } while (temp != first);

    printf("Element not present in this list!\n");
}

void display(Node** last) {
    if (*last == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* first = (*last)->next;
    Node* temp = first;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != first);

    printf("First element\n");
}

int main() {
    Node* last = NULL;

    insert(&last, 10);
    insert(&last, 20);
    insert(&last, 30);
    insert(&last, 40);
    insert(&last, 50);

    printf("Original list: \n");
    display(&last);

    delete(&last, 40);

    printf("Modified list: \n");
    display(&last);

    return 0;
}
