// Implementing circular linked list

#include <stdio.h>
#include <stdlib.h>

void insertAtBegin();
void insertAtEnd();
void insertAtPosition();
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPosition();
void display();
void search();
int length();

typedef struct node {
    struct node * prev;
    int data;
    struct node * next;
}Node;

Node * head = NULL;

int main() {

    return 0;
}

int length() {
    if(head == NULL)
        return 0;
    Node * temp = head;
    int count = 1;
    while(temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

void insertAtBegin() {
    Node * new = (Node *)malloc(sizeof(Node));
    printf("\nEnter the value: ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = head;
    if(head != NULL) 
        head->prev = new;
    head = new;
    printf("Node inserted\n");
}

void insertAtEnd() {
    if(head == NULL)
        insertAtBegin();
    else {
        Node * temp = head;
        while(temp->next != NULL) 
            temp = temp->next;
        Node * new = (Node *)malloc(sizeof(Node));
        printf("\nEnter the value: ");
        scanf("%d", &new->data);
        new->prev = temp;
        new->next = NULL;
        temp->next = new;
        printf("Node inserted\n");
    }
}

void insertAtPosition() {
    int count = length();
    int pos;
    printf("\nEnter the position: ");
    scanf("%d", &pos);
    if(pos == 1)
        insertAtBegin();
    else if(pos == (count+1))
        insertAtEnd();
    else if(pos>1 && pos<=count) {
        Node * temp = head;
        for(int i=1; i<(pos-1); i++) 
            temp = temp->next;
        Node * new = (Node *)malloc(sizeof(Node));
        printf("\nEnter the value: ");
        scanf("%d", &new->data);
        new->prev = temp;
        new->next = temp->next;
        temp->next->prev = new;
        temp->next = new;
        printf("Node inserted\n");
    }
}

void deleteAtBegin() {}

void deleteAtEnd() {}

void deleteAtPosition() {}

void display() {}

void search() {}