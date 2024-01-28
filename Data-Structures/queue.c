// Implementing queue using arrays

#include <stdio.h>
#include <stdlib.h>

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

void insert() {
    if(rear == (num-1)) {
        printf("\nQueue is full\n");
        return;
    }

    int x;
    printf("\nEnter value: ");
    scanf("%d", &x);
    rear++;
    queue[rear] = x;
    printf("Inserted\n");
}

void dele() {
    if(rear == -1) {
        printf("\nQueue is empty, cannot delete element.\n");
        return;
    }

    front++;
    int x = queue[front];
    if(front == rear)
        front = rear = -1;
    printf("\nDeleted %d\n", x);
}

void display() {
    if(rear == -1) {
        printf("\nThere are no elements in the queue\n");
        return;
    }

    printf("\nThe elements in the queue are: \n");
    for(int i=0; i<=rear; i++) {
        if(i<=front)
            printf("- ");
        else
            printf("%d ", queue[i]); 
    }
    printf("\n");
}

void search() {
    if(rear == -1) {
        printf("\nThere are no elements in the queue\n");
        return;
    }
    int key;
    printf("\nEnter the key value: ");
    scanf("%d", &key);
    int flag=1;
    for(int i=front+1; i<=rear; i++) {
        if(queue[i] == key) {
            printf("Found at position: %d\n", i+1);
            flag = 0;
        }
    }
    if(flag)
        printf("Key not found in the queue\n");
}