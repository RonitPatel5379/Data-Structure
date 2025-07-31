#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* insertAtEnd(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head==NULL) {
    newNode->prev = NULL;
    return newNode;
  }
  struct Node* temp = head;
  while(temp->next!=NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
  return head;
}

struct Node* deleteAlternate(struct Node* head) {
  if(head==NULL) {
    return NULL;
  }
  struct Node* temp = head->next;
  struct Node* prev = head;
  while(temp!=NULL) {
    prev->next = temp->next;
    if(temp->next!=NULL) {
      temp->next->prev = prev;
    }
    free(temp);
    prev = prev->next;
    if(prev!=NULL) {
      temp = prev->next;
    }
    else {
      break;
    }
  }
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
  head = insertAtEnd(head,10);
  head = insertAtEnd(head,20);
  head = insertAtEnd(head,30);
  head = insertAtEnd(head,40);
  head = insertAtEnd(head,50);

  head = deleteAlternate(head);
  printf("Delete Alternate Node:");
  display(head);
}           