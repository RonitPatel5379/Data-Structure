#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* inserAtEnd(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head==NULL) {
    newNode->next = newNode;
    head = newNode;
  }
  else {
    struct Node* temp = head;
    while(temp->next!=head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
  return head;
}

void splitList(struct Node* head, struct Node* head1, struct Node* head2) {
    // if (head == NULL || head->next == head) {
    //     head1 = head;
    //     head2 = NULL;
    // }
    struct Node* temp = head;
    struct Node* temp1 = head;
    while (temp1->next != head && temp1->next->next != head) {
        temp = temp->next;
        temp1 = temp1->next->next;
    }
    if (temp1->next->next == head) {
        temp1 = temp1->next;
    }
      head1 = head;
      head2 = temp->next;
      temp->next = head1;
      temp1->next = head2;
}

void display(struct Node* head) {
  // if(head==NULL) {
  //   printf("List is empty.");
  //   return;
  // }
  struct Node* temp = head;
  while(temp->next!=head) {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  printf("%d -> ",temp->data);
}

void main() {
  struct Node* head = NULL;
  struct Node* head1 = NULL;
  struct Node* head2 = NULL;
  head = inserAtEnd(head,10);
  head = inserAtEnd(head,20);
  head = inserAtEnd(head,30);
  head = inserAtEnd(head,40);
  printf("Linked List:");
  display(head);
  splitList(head,head1,head2);
  printf("\nFirst Part:");
  display(head1);
  printf("\nSecond Part:");
  display(head2);
}