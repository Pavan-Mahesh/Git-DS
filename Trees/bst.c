#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left, * right;
}node;

node * createNew(int val) {
    node * new = (node *)malloc(sizeof(node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}

node * insert(node * root, int val) {
    if(root == NULL)
        root = createNew(val);
    if(root->data > val)
        root->left = insert(root->left, val);
    else if(root->data < val)
        root->right = insert(root->right, val);
    return root;
}

node * delete(node * root, int val) {
    if(root == NULL)
        return NULL;
    else if(root->data > val)
        root->left = delete(root->left, val);
    else if(root->data < val)
        root->right = delete(root->right, val);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if(root->left == NULL) {
            node * temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            node * temp = root->left;
            free(root);
            return temp;
        } else {
            node * temp = root->right;
            while(temp->left != NULL)
                temp = temp->left;
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
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
    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    // Delete a node from the BST
    root = delete(root, 10);

    // Inorder traversal of the BST after deletion
    printf("Inorder traversal of the BST after deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}