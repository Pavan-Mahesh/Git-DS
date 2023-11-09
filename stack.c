// Implementing stack using arrays

#include <stdio.h>
#include <stdlib.h>

int isempty();
int isfull();
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

int isempty() {
    if(top == -1)
        return 1;
    else
        return 0; 
}

int isfull() {
    if(top == (num-1))
        return 1;
    else
        return 0; 
}

void push() {
    if(isfull())
        printf("\nStack is full, cannot perform push operation.\n");
    else {
        int x;
        printf("\nEnter value: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element inserted\n");
    }
}

void pop() {
    if(isempty())
        printf("\nStack is empty, cannot perform pop operation.\n");
    else {
        int x;
        x = stack[top];
        top--;
        printf("\nPoped value: %d.\n", x);
    }
}

void display() {
    if(isempty())
        printf("\nThere are no elements in the stack.\n");
    else {
        printf("\nThe elements in the stack are: \n");
        for(int i=0; i<num; i++) {
            if(i <= top)
                printf("%d ", stack[i]);
            else
                printf("- ");
        }
        printf("\n");
    }
}

void search() {
    if(isempty())
        printf("\nThere are no elements in the stack\n");
    else {
        int key;
        printf("\nEnter the key value: ");
        scanf("%d", &key);
        int flag=0, pos;
        for(int i=0; i<=top; i++) {
            if(stack[i] == key) {
                flag = 1;
                pos = i;
                break;
            }
        }
        if(flag)
            printf("Key: %d found at position: %d\n", key, pos+1);
        else 
            printf("Key not found in the stack\n");
    }
}