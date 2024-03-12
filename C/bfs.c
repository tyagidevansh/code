#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BFS(Node* root) {
    if (root == NULL) 
        return;
    
    Node** queue = (Node**)malloc(sizeof(Node) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d", curr->val);

        if (curr -> left != NULL) 
            queue[rear++] = curr->left;
        
        if (curr -> right != NULL) 
            queue[rear++] = curr->right;
    }
    free(queue);
}

int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Breadth First Traversal of the binary tree is: ");
    BFS(root);
    printf("\n");

    return 0;
}