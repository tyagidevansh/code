#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        Node* newNode = createNode(data);
        root = newNode;
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    } else if (root->data < key) {
        return search(root->right, key);
    } else if (root->data > key) {
        return search(root->left, key);
    }
    printf("Element not found! \n");
}

Node* delete(Node* root, int key) {
    if (root == NULL)
        return root;
    
    if (root->data > key) {
        root->left = delete(root->left, key);
    } else if (root->data < key) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = root->right;
        while (temp->left!=NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

int main() {
    Node* root = (Node*)malloc(sizeof(Node));
    root = NULL;
    root = insert(root, 25);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 30);
    root = insert(root, 54);
    root = insert(root, 20);
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    root = delete(root, 3);
    root = delete(root, 20);
    inOrder(root);
    printf("\n");
    Node* searchResult = search(root, 10);
    printf("%d", searchResult->data);
    return 0;
}