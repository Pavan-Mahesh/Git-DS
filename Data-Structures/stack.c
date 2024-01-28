// Implementing stack using arrays

#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void search();

int stack[100], top=-1, num;

int main() {
    printf("\nEnter the size of the stack: ");
    scanf("%d", &num);
    
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
    if(top == (num-1))
        printf("\nStack is full\n");
    else {
        int x;
        printf("\nEnter value: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\nPushed\n");
    }
}

void pop() {
    if(top == 0)
        printf("\nStack is empty\n");
    else {
        int x;
        x = stack[top];
        top--;
        printf("\nPoped %d\n", x);
    }
}

void display() {
    if(top == 0) {
        printf("\nThere are no elements in the stack.\n");
        return;
    }
    printf("\nElements in the stack are: \n");
    for(int i=0; i<num; i++) {
        if(i <= top)
            printf("%d ", stack[i]);
        else
            printf("- ");
    }
    printf("\n");
}

void search() {
    if(top == 0) {
        printf("\nThere are no elements in the stack\n");
        return;
    }
    int key;
    printf("\nEnter the key value: ");
    scanf("%d", &key);
    int flag=1;
    for(int i=0; i<=top; i++) {
        if(stack[i] == key) {
            printf("Found at position: %d\n", i+1);
            flag = 0;
        }
    }
    if(flag)
        printf("Key not found\n");
}