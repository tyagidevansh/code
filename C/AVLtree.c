#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int height(struct Node* N) {
    if (N == NULL) 
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Node* newNode (int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> height = 1; //new node is initially added at leaf
    return(newNode);
}
/*
     y                               x
    / \     Right Rotation          /  \
   x   T3   - - - - - - - >        T1   y 
  / \       < - - - - - - -            / \
 T1  T2     Left Rotation            T2  T3
*/

Node* rightRotate(Node* y) {
    Node* x = y -> left;
    Node* T2 = x -> right;

    x -> right = y;
    y -> left = T2;

    y -> height = max(height(y->left), height(y->right)) + 1;
    x -> height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x -> right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x -> height = max(height(x->left), height(x->right)) + 1;
    y -> height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node* N) {
    if (N == NULL) 
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int data) {
    //1. Perform normal BST insertion
    if (node == NULL)
        return newNode(data);
    if (data < node -> data)
        node -> left = insert(node->left, data);
    else if (data > node -> data) 
        node -> right = insert(node->right, data);
    else //equal keys are not allowed in BST
        return node;

    //2. Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    //3. Get the balance factor of this ancestor node to check whether this node became unbalanced
    int balance = getBalance(node);

    //If this node became unbalanced there are 4 cases:

    //LL
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    
    //RR
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    
    //LR
    if (balance > 1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);   
    }
    
    //RL
    if (balance < -1 && data < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root){
    if (root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Preorder traversal: \n");
    preOrder(root);

    return 0;
}