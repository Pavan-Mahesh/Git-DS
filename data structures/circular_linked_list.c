// Implementing circular linked list

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * link;
};

struct node * head = NULL;
int count = 0;

void insertAtBegin(int x);
void insertAtEnd(int x);
void insertAtPosition(int x, int pos);
void deleteAtBegin();
void deleteAtEnd();
void deleteAtPosition(int pos);
void display();
void search(int key);

int main() {
    printf("\nInsert at the beginning: ");
    insertAtBegin(70);
    insertAtBegin(120);
    insertAtBegin(90);
    display();

    printf("\nInsert at the end: ");
    insertAtEnd(60);
    insertAtEnd(45);
    insertAtEnd(105);
    display();

    printf("\nInsert at a given position: ");
    insertAtPosition(30, 2);
    insertAtPosition(85, 5);
    insertAtPosition(50, 7);
    display();

    search(90);
    search(115);

    printf("\nDelete at the beginning: ");
    deleteAtBegin();
    deleteAtBegin();
    display();

    printf("\nDelete at the end: ");
    deleteAtEnd();
    deleteAtEnd();
    display();

    printf("\nDelete at a given position: ");
    deleteAtPosition(4);
    deleteAtPosition(2);
    display();

    return 0;
}

void insertAtBegin(int x) {
    struct node * new; 
    new = (struct node * )malloc(sizeof(struct node));
    new->data = x;
    new->link = head;
    head = new;
    if(new->link == NULL)
        new->link = head;
    else {
        struct node * temp = new->link;
        while(temp->link != new->link) 
            temp = temp->link;
        temp->link = head;
    }
    printf("\nAdded: %d at the begin", x);
    count++;
}

void insertAtEnd(int x) {
    if(head == NULL) 
        insertAtBegin(x);
    else {
        struct node * temp = head;
        while(temp->link != head)
            temp = temp->link;
        struct node * new;
        new = (struct node * )malloc(sizeof(struct node));
        new->data = x;
        new->link = head;
        temp->link = new;
        printf("\nAdded: %d at the end", x);
        count++;
    }
}

void insertAtPosition(int x, int pos) {
    if(pos<=0 || pos>(count+1)) {
        printf("Cannot insert at the given location");
        return;
    }
    if(pos == 1) 
        insertAtBegin(x);
    else if(pos == (count+1))
        insertAtEnd(x);
    else {
        struct node * temp = head;
        for(int i=1; i<(pos-1); i++) 
            temp = temp->link;
        struct node * new;
        new = (struct node * )malloc(sizeof(struct node));
        new->data = x;
        new->link = temp->link;
        temp->link = new;
        printf("\nAdded: %d at position %d", x, pos);
        count++;
    }
}

void deleteAtBegin() {
    if(head == NULL) {
        printf("\nCircular linked list is empty\n");
        return;
    }

    struct node * temp = head;
    if(head->link == head)
        head = NULL;
    else {
        while(temp->link != head) 
            temp = temp->link;
        temp->link = head->link;
        temp = head;
        head = head->link;
    }
    printf("\nDeleted: %d at the begin", temp->data);
    free(temp);
    count--;
}

void deleteAtEnd() {
    if(head == NULL) {
        printf("\nCircular linked list is empty\n");
        return;
    }

    if(head->link == head) 
        deleteAtBegin();
    else {
        struct node * prev = head;
        struct node * temp = head->link;
        while(temp->link != head) {
            temp = temp->link;
            prev = prev->link;
        }
        prev->link = head;
        printf("\nDeleted: %d at the end", temp->data);
        free(temp);
        count--;
    }
}

void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("\nCircular linked list is empty");
        return;
    }

    if(pos<=0 || pos>count) {
        printf("Cannot delete at the given position");
        return;
    }
    if(pos == 1)
        deleteAtBegin();
    else if(pos == count)
        deleteAtEnd();
    else if(pos>1 && pos<count) {
        struct node * prev = head;
        struct node * temp = head->link;
        for(int i=2; i<pos; i++) {
            temp = temp->link;
            prev = prev->link;
        }
        prev->link = temp->link;
        printf("\nDeleted: %d at position %d", temp->data, pos);
        free(temp);
        count--;
    }
}

void display() {
    if(head == NULL) {
        printf("\nNo elements in the linked list\n");
        return;
    }
    
    struct node * temp = head;
    printf("\nElements in the linked list are: \n");
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } while(temp != head);
    printf("\n");
}

void search(int key) {
    if(head == NULL) {
        printf("\nNo elements in the linked list\n");
        return;
    }

    struct node * temp = head;
    int flag=1, pos=1;
    printf("\nSearching %d: \n", key);
    do {
        if(temp->data == key) {
            printf("Found at position: %d", pos);
            flag = 0;
        }
        temp = temp->link;
        pos++;
    } while(temp != head);
    if(flag)
        printf("Key not found");
    printf("\n");
}