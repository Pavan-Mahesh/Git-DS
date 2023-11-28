#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * link;
}Node;

Node * rear = NULL;
Node * front = NULL;

void insert();
void dele();
void display();
void search();

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
    printf("Inserted\n", new->data);
}

void dele() {
    if(rear == NULL) {
        printf("\nQueue is empty\n");
        return;
    }

    Node * temp = front;
    front = front->link;
    if(front == NULL)
        rear = NULL;
    printf("\nDeleted %d\n", temp->data);
    free(temp);
}

void display() {
    if(rear == NULL) {
        printf("\nNo elements in the queue\n");
        return;
    }
    
    Node * temp = front;
    printf("\nElements in the queue are: \n");
    printf("front --> ");
    while(temp != NULL) {
        printf("%d --> ", temp->data);
        temp = temp->link;
    }
    printf("rear");
    printf("\n");
}

void search() {
    if(rear==NULL) {
        printf("\nNo elements in the queue\n");
        return;
    }
    
    int key;
    printf("\nEnter the key: ");
    scanf("%d", &key);
    Node * temp = front;
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