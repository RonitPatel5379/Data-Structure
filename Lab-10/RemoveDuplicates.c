#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void removeDuplicates(struct node* head) {
    struct node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct node* temp1 = temp->next;
            temp->next = temp1->next;
            free(temp1);
        } else {
            temp = temp->next;
        }
    }
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

void main() {
    struct node* head = NULL;
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,13);
    head = insertAtEnd(head,13);
    head = insertAtEnd(head,13);
    head = insertAtEnd(head,27);
    head = insertAtEnd(head,27);

    printf("Original List:\n");
    display(head);

    removeDuplicates(head);

    printf("List After Removing Duplicates:\n");
    display(head);
}