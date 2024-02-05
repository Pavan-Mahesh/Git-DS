#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left, * right;
    int height;
}node;

node * createNew(int val) {
    node * new = (node *)malloc(sizeof(node));
    new->data = val;
    new->left = new->right = NULL;
    new->height = 1;
    return new;
}

int getHeight(node * n) {
    if(n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getBF(node * n) {
    if(n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node * leftRotate(node * x) {
    node * y = x->right;
    node * z = y->left;
    y->left = x;
    x->right = z;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

node * rightRotate(node * x) {
    node * y = x->left;
    node * z = y->right;
    y->right = x;
    x->left = z;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

node * insert(node * root, int val) {
    if(root == NULL) 
        root = createNew(val);
    else if(root->data < val)
        root->right = insert(root->right, val);
    else if(root->data > val)
        root->left = insert(root->left, val);

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBF(root);
    if(bf > 1 && val < root->left->data){
        return rightRotate(root);
    } else if(bf < -1 && val > root->right->data) {
        return leftRotate(root);
    } else if(bf > 1 && val > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    } else if(bf < -1 && val < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(node * root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    node * root = NULL;

    // Insert some nodes into the BST
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 20);

    // Inorder traversal of the BST
    printf("Inorder traversal of the BST: \n");
    inorder(root);
    printf("\n");
    return 0;
}