// Implement stack using linked list

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void search();

typedef struct Node {
    int data;
    struct Node * link;
}Node;

Node * top = NULL;

int main() {
    int ch;
    while(1) {
        printf("\nStack Operations: ");
        printf("\n1. push\n2. pop\n3. display\n4. search\n5. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5: 
                printf("\nExited\n");
                exit(0);
                break;
            default: 
                printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}

void push() {
    int x;
    printf("\nEnter the element: ");
    scanf("%d", &x);
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->link = top;
    top = new;
}

void pop() {
    if(top==NULL)
        printf("\nStack is empty, cannot perform pop operation.\n");
    else {
        Node * temp = top;
        top = temp->link;
        printf("\nPoped element: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if(top == NULL)
        printf("\nNo elements in the stack\n");
    else {
        Node * temp = top;
        printf("\nThe elements in the stack are: \n");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void search() {
    if(top==NULL)
        printf("\nNo elements in the queue\n");
    else {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        Node * temp = top;
        int flag=0, pos=1;
        while(temp != NULL) {
            if(temp->data == key) {
                printf("Key: %d found at position: %d\n", key, pos);
                flag=1;
            }
            temp = temp->link;
            pos++;
        }
        if(!flag)
            printf("Key not found in the queue\n");
    }
}