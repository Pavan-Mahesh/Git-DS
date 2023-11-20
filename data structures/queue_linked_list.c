#include <stdio.h>
#include <stdlib.h>

void insert();
void dele();
void display();
void search();

typedef struct node {
    int data;
    struct node * link;
}Node;

Node * rear = NULL;
Node * front = NULL;

int main() {
    int ch;
    while(1) {
        printf("\nQueue Operations: ");
        printf("\n1. insert\n2. delete\n3. display\n4. search\n5. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                insert();
                break;
            case 2:
                dele();
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

void insert() {
    Node * new = (Node *)malloc(sizeof(Node));
    printf("\nEnter value: ");
    scanf("%d", &new->data);
    new->link = NULL;
    if(rear != NULL)
        rear->link = new;
    rear = new;
    if(front == NULL)
        front = new;
    printf("Node inserted\n");
}

void dele() {
    if(rear == NULL)
        printf("\nQueue is empty\n");
    else {
        Node * temp = front;
        front = front->link;
        if(front == NULL)
            rear = NULL;
        printf("\nDeleted value: %d\n", temp->data);
        free(temp);
    }
}

void display() {
    if(rear == NULL)
        printf("\nNo elements in the queue\n");
    else {
        Node * temp = front;
        printf("\nThe elements in the queue are: \n");
        while(temp != NULL) {
            printf("%d --> ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void search() {
    if(rear==NULL)
        printf("\nNo elements in the queue\n");
    else {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        Node * temp = front;
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