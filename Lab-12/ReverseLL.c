#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* temp = head;
    struct Node* next = NULL;

    while (temp!=NULL) {
        next = temp->next;
        temp->next = prev;   
        prev = temp;         
        temp = next;
    }
    head = prev;
    return head;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while(temp!=NULL) {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
}

void main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    printf("Original List: ");
    display(head);
    head = reverseList(head);
    printf("\nReversed List: ");
    display(head);
}