// Implementing linked list

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

typedef struct node {
    int data;
    struct node * link;
}Node;

Node * head = NULL;

int main() {
    return 0;
}