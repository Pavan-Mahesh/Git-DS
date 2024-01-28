// Implement stack using linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node * link;
}Node;

Node * top = NULL;

void push();
void pop();
void display();
void search();

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
    Node * new = (Node *)malloc(sizeof(Node));
    printf("\nEnter the element: ");
    scanf("%d", &new->data);
    new->link = top;
    top = new;
    printf("Pushed\n");
}

void pop() {
    if(top == NULL) {
        printf("\nStack is empty, cannot perform pop operation.\n");
        return;
    }

    Node * temp = top;
    top = top->link;
    printf("\nPoped %d\n", temp->data);
    free(temp);
}

void display() {
    if(top == NULL) {
        printf("\nNo elements in the stack\n");
        return;
    }

    Node * temp = top;
    printf("\nElements in the stack are: \n");
    printf("top");
    while(temp != NULL) {
        printf(" --> %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void search() {
    if(top==NULL) {
        printf("\nNo elements in the stack\n");
        return;
    }

    int key;
    printf("\nEnter the key: ");
    scanf("%d", &key);
    Node * temp = top;
    int flag=1, pos=1;
    while(temp != NULL) {
        if(temp->data == key) {
            printf("Found at position: %d\n", pos);
            flag=0;
        }
        temp = temp->link;
        pos++;
    }
    if(flag)
        printf("Key not found\n");
}