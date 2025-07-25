#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* push(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  head = newNode;
  return head;
}

struct Node* pop(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
  }
  else {
    struct Node* temp = head;
    head = head->next;
    free(temp);
  }
  return head;
}

struct Node* display(struct Node* head) {
  struct Node* temp = head;
  while(temp!=NULL) {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  return head;
}

void main() {
  struct Node* head = NULL;
  head = push(head,10);
  head = push(head,20);
  head = push(head,30);
  head = push(head,40);
  head = pop(head);
  printf("Stack Using SLL:");
  display(head);
}