// Implementing queue using arrays

#include <stdio.h>
#include <stdlib.h>

int isempty();
int isfull();
void insert();
void dele();
void display();
void search();

int queue[100], rear=-1, front=-1, num;

int main() {
    printf("\nEnter the size of the queue: ");
    scanf("%d", &num);
    
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

int isempty() {
    if(rear == -1)
        return 1;
    else
        return 0;
}

int isfull() {
    if(rear == (num-1))
        return 1;
    else
        return 0;
}

void insert() {
    if(isfull())
        printf("\nQueue is full, cannot insert element.\n");
    else {
        int x;
        printf("\nEnter the element: ");
        scanf("%d", &x);
        rear++;
        queue[rear] = x;
        printf("Element inserted\n");
    }
}

void dele() {
    if(isempty())
        printf("\nQueue is empty, cannot delete element.\n");
    else {
        front++;
        int x = queue[front];
        if(front == rear)
            front = rear = -1;
        printf("\nDeleted element: %d\n", x);
    }
}

void display() {
    if(isempty())
        printf("\nThere are no elements in the queue\n");
    else {
        printf("\nThe elements in the queue are: \n");
        for(int i=0; i<=rear; i++) {
            if(i<=front)
                printf("- ");
            else
                printf("%d ", queue[i]); 
        }
        printf("\n");
    }
}

void search() {
    if(isempty())
        printf("\nThere are no elements in the queue\n");
    else {
        int key;
        printf("\nEnter the key value: ");
        scanf("%d", &key);
        int flag=0, pos;
        for(int i=front+1; i<=rear; i++) {
            if(queue[i] == key) {
                flag = 1;
                pos = i;
                break;
            }
        }
        if(flag)
            printf("Key: %d found at position: %d\n", key, pos+1);
        else 
            printf("Key not found in the queue\n");
    }
}