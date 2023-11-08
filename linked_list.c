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
    int ch;
    while(1) {
        printf("\nLinked List Operations: \n");
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

void insertAtBegin() {
    int x;
    printf("\nEnter value: ");
    scanf("%d", &x);
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->link = head;
    head = new;
    printf("Node inserted\n");
}

void insertAtEnd() {
    if(head == NULL)
        insertAtBegin();
    else {
        int x;
        printf("\nEnter value: ");
        scanf("%d", &x);
        Node * new = (Node *)malloc(sizeof(Node));
        new->data = x;
        new->link = NULL;
        Node * temp = head;
        while(temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = new;
        printf("Node inserted\n");
    }
}

void insertAtPosition() {
    Node * temp = head;
    int count = 1;
    while(temp->link != NULL) {
        temp = temp->link;
        count++; 
    }
    int p;
    printf("\nEnter the position: ");
    scanf("%d", &p);

    if(p==1)
        insertAtBegin();
    else if(p==(count+1))
        insertAtEnd();
    else if(p>1 && p<(count+1)) {
        int x;
        printf("\nEnter value: ");
        scanf("%d", &x);
        Node * new = (Node *)malloc(sizeof(Node));
        new->data = x;
        temp = head;
        for(int i=1; i<(p-1); i++)
            temp = temp->link;
        new->link = temp->link;
        temp->link = new;
        printf("Node inserted\n");
    } else {
        printf("Cannot insert node at the given position\n");
    }
}

void deleteAtBegin() {
    if(head==NULL)
        printf("\nLinked list is empty, cannot perform delete operation.\n");
    else {
        Node * temp = head;
        head = temp->link;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd() {
    if(head==NULL)
        printf("\nLinked list is empty, cannot perform delete operation.\n");
    else {
        if(head->link == NULL) {
            deleteAtBegin();
        } else {
            Node * prev = head;
            Node * temp = head->link;
            while(temp->link != NULL) {
                temp = temp->link;
                prev = prev->link;
            }
            prev->link = NULL;
            printf("\nDeleted element: %d\n", temp->data);
            free(temp);
        }
    }
}

void deleteAtPosition() {
    if(head==NULL)
        printf("\nLinked list is empty, cannot perform delete operation.\n");
    else {
        Node * temp = head;
        int count = 1;
        while(temp->link != NULL) {
            temp = temp->link;
            count++;
        }
        int p;
        printf("\nEnter the position: ");
        scanf("%d", &p);

        if(p==1) {
            deleteAtBegin();
        } else if(p==count) {
            deleteAtEnd();
        } else if(p>1 && p<count) {
            Node * prev = head;
            temp = head->link;
            for(int i=2; i<p; i++) {
                temp = temp->link;
                prev = prev->link;
            }
            prev->link = temp->link;
            printf("\nDeleted element: %d\n", temp->data);
            free(temp);
        } else {
            printf("Cannot delete node at the given position\n");
        }
    }
}

void display() {
    if(head == NULL)
        printf("\nNo elements in the linked list\n");
    else {
        Node * temp = head;
        printf("\nThe elements in the linked list are: \n");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void search() {
    if(head==NULL)
        printf("\nNo elements in the linked list\n");
    else {
        int key;
        printf("\nEnter the key: ");
        scanf("%d", &key);
        Node * temp = head;
        int flag=0, pos=1;
        while(temp != NULL) {
            if(temp->data == key) {
                printf("Key: %d found at position: %d\n", key, pos);
                flag=1;
            }
            temp = temp->link;
            pos++;
        }
        if(!flag)
            printf("Key not found in the queue\n");    
    }
}
