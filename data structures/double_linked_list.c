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
    int ch;
    while(1) {
        printf("\nDouble linked list operations: ");
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
    } else 
        printf("Cannot insert at the given location\n");
}

void deleteAtBegin() {
    if(head == NULL) 
        printf("\nDouble linked list is empty\n");
    else {
        Node * temp = head;
        head = head->next;
        if(head != NULL) 
            head->prev = NULL;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd() {
    if(head == NULL)
        printf("\nDouble linked list is empty\n");
    else {
        if(head->next == NULL)
            deleteAtBegin();
        Node * temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtPosition() {
    if(head == NULL)
        printf("\nDouble linked list is empty\n");
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
            Node * temp = head;
            for(int i=1; i<pos; i++) 
                temp = temp->next;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            printf("\nDeleted element: %d\n", temp->data);
            free(temp);
        } else 
            printf("Cannot delete at the given location\n");
    }
}

void display() {
    if(head == NULL) 
        printf("\nNo elements in the double linked list\n");
    else {
        Node * start = head, * end;
        printf("\nElements in the linked are: \n");
        while(start != NULL) {
            printf("%d --> ", start->data);
            end = start;
            start = start->next;
        }
        printf("\n");
        while(end != NULL) {
            printf("%d <-- ", end->data);
            end = end->prev;
        }
        printf("\n");
    }
}

void search() {
    if(head == NULL) 
        printf("\nNo elements in the double linked list\n");
    else {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        Node * temp = head;
        int flag=0, pos=1;
        while(temp != NULL) {
            if(temp->data == key) {
                printf("Found at position: %d\n", pos);
                flag=1;
            }
            temp = temp->next;
            pos++;
        }
        if(!flag)
            printf("Key element not found\n");
         
    }
}