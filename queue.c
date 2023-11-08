// Implementing queue using arrays

#include <stdio.h>
#include <stdlib.h>

int isempty();
int isfull();
void insert();
void dele();
void display();

int queue[100], rear=-1, front=-1, num;

int main() {
    printf("\nEnter the size of the queue: ");
    scanf("%d", &num);
    
    int ch;
    while(1) {
        printf("\nQueue Operations: ");
        printf("\n1. insert\n2. delete\n3. display\n4. exit");
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
        printf("\nThere is no elements in the queue.\n");
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