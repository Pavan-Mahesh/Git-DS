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
    int data;
    struct node * link;
}Node;

Node * head = NULL;

int main() {
    int ch;
    while(1) {
        printf("\nCircular linked list operations: ");
        printf("\n1. insert at begin\n2. insert at end\n3. insert at position");
        printf("\n4. delete at begin\n5. delete at end\n6. delete at position");
        printf("\n7. display\n8. search\n9. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            insertAtBegin();
            break;
        case 2:
            insertAtEnd();
            break;
        case 3:
            insertAtPosition();
            break;
        case 4:
            deleteAtBegin();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            display();
            break;
        case 8:
            search();
            break;
        case 9:
            printf("\nExited\n");
            exit(0);
            break;
        default:
            printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}

int length() {
    if(head == NULL)
        return 0;
    Node * temp = head;
    int count = 1;
    while(temp->link != head) {
        temp = temp->link;
        count++;
    }
    return count;
}

void insertAtBegin() {
    Node * new = (Node * )malloc(sizeof(Node));
    printf("\nEnter the value: ");
    scanf("%d", &new->data);
    new->link = head;
    head = new;
    if(new->link == NULL)
        new->link = head;
    else {
        Node * temp = new->link;
        while(temp->link != new->link) 
            temp = temp->link;
        temp->link = head;
    }
    printf("Node inserted\n");
}

void insertAtEnd() {
    if(head == NULL) 
        insertAtBegin();
    else {
        Node * temp = head;
        while(temp->link != head)
            temp = temp->link;
        Node * new = (Node * )malloc(sizeof(Node));
        printf("\nEnter the value: ");
        scanf("%d", &new->data);
        new->link = head;
        temp->link = new;
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
            temp = temp->link;
        Node * new = (Node * )malloc(sizeof(Node));
        printf("\nEnter the value: ");
        scanf("%d", &new->data);
        new->link = temp->link;
        temp->link = new;
        printf("Node inserted\n");
    } else 
        printf("Cannot insert at the given position\n");
}

void deleteAtBegin() {
    if(head == NULL) 
        printf("\nCircular linked list is empty\n");
    else {
        Node * temp = head;
        if(head->link == head)
            head = NULL;
        else {
            while(temp->link != head) 
                temp = temp->link;
            temp->link = head->link;
            temp = head;
            head = head->link;
        }
        printf("\nDeleted value: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd() {
    if(head == NULL)
        printf("\nCircular linked list is empty\n");
    else {
        if(head->link == head) 
            deleteAtBegin();
        else {
            Node * prev = head;
            Node * temp = head->link;
            while(temp->link != head) {
                temp = temp->link;
                prev = prev->link;
            }
            prev->link = head;
            printf("\nDeleted value: %d\n", temp->data);
            free(temp);
        }
    }
}

void deleteAtPosition() {
    if(head == NULL) 
        printf("\nCircular linked list is empty\n");
    else {
        int count = length();
        int pos;
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if(pos == 1)
            deleteAtBegin();
        else if(pos == count)
            deleteAtEnd();
        else if(pos>1 && pos<count) {
            Node * prev = head;
            Node * temp = head->link;
            for(int i=2; i<pos; i++) {
                temp = temp->link;
                prev = prev->link;
            }
            prev->link = temp->link;
            printf("Deleted value: %d\n", temp->data);
            free(temp);
        } else 
        printf("Cannot delete at the given position\n");
    }
}

void display() {
    if(head == NULL)
        printf("\nNo elements in the linked list\n");
    else {
        Node * temp = head;
        printf("\nElements in the linked list are: \n");
        do {
            printf("%d --> ", temp->data);
            temp = temp->link;
        } while(temp != head);
        printf("\n");
    }
}

void search() {
    if(head == NULL)
        printf("\nNo elements in the linked list\n");
    else {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        Node * temp = head;
        int flag=0, pos=1;
        do {
            if(temp->data == key) {
                printf("Found at position: %d\n", pos);
                flag = 1;
            }
            temp = temp->link;
            pos++;
        } while(temp != head);
        if(!flag)
            printf("Key element not found\n");
    }
}