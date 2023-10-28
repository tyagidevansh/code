#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if (root == NULL) {
        return createNode(data);
    }

    if (data <= root -> data) 
        root->left = insert(root->left, data);
    else if (data > root -> data)
        root -> right = insert(root->right, data);

    return root;
}

void inOrderTraversal(Node* node) {
    if (node != NULL){
    inOrderTraversal(node->left);
    printf("%d ", node -> data);
    inOrderTraversal(node->right);
    }
}

void preOrderTraversal(Node* node) {
    if (node != NULL){
    printf("%d ", node -> data);
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
    }
}

void postOrderTraversal(Node* node) {
    if (node != NULL){
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node -> data);
    }
}

Node* search(Node* root, int key) {
    if (root == NULL){
        return NULL;
    }

    if (root -> data == key){
        return root;
    } else if (root -> data > key) {
        return search(root -> left, key);
    } else {
        return search(root -> right, key);
    }
}

Node* deleteNode(Node* root, int val) {
    if (root == NULL)
        return root;
    
    if (root->data > val) {
        root->left = deleteNode(root->left, val);
        return root;
    } else if (root->data < val) {
        root->right = deleteNode(root->right, val);
    }

    if (root->left == NULL) {
        Node* temp = root->right;
        free(root);
        return temp;
    } else if (root->right == NULL) {
        Node* temp = root->left;
        free(root);
        return temp;
    } else {
        Node* sp = root;
        
        Node* succ = root -> right;
        while (succ -> left != NULL) {
            sp = succ;
            succ = succ -> left;
        }

        if (sp != root) 
            sp->left = succ->right;
        else
            sp->right = succ->right;
        
        root->data = succ->data;

        free(succ);
        return root;

    }
}

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: \n");
    inOrderTraversal(root);
    printf("\nPre-order traversal: \n");
    preOrderTraversal(root);
    printf("\nPost-order traversal: \n");
    postOrderTraversal(root);
    printf("\n");

    Node* searchResult = search(root, 100);
    if (searchResult != NULL){
        printf("Element found: %d ", searchResult -> data);
    } else {
        printf("Element not found!");
    }

    root = deleteNode(root, 20);

    printf("In-order traversal: \n");
    inOrderTraversal(root);

    return 0;
}