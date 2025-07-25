#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertfront(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertend(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(){
    if (head == NULL) {
        printf("List is empty.\n");
    }else {
        struct Node* temp = head;
        printf("Linked list: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void deletefront() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } 
}

void deleteend() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("Last node deleted.\n");
    }
}

void deleteposition(int pos) {
   if (head == NULL) {
        printf("List is empty.\n");
    } else if (pos == 1) {
        deletefront();
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1 ; i++) {
            if( temp != NULL){
                temp = temp->next;
        }
    }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position.\n");
        } else {
            struct Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            printf("Node at position %d deleted.\n", pos);
        }
    }
}

void countnodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

void main(){
    int value;
    int choice,pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Delete front node\n");
        printf("4. Delete end node\n");
        printf("5. Delete node at position\n");
        printf("6. Display list\n");
        printf("7. Count nodes\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertfront(value);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            insertend(value);
        } else if (choice == 3) {
            deletefront();
        } else if (choice == 4) {
            deleteend();
        } else if (choice == 5) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteposition(pos);
        } else if (choice == 6) {
            display();
        } else if (choice == 7) {
            countnodes();
        } else if (choice == 8) {
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}