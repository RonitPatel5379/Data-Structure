#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtEnd(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if(head==NULL) {
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    return;
  }
  newNode->data = data;
  newNode->next = NULL;
    struct Node* temp = head;
    while(temp->next!=NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

struct Node* sortedList(struct Node* head) {
  if(head==NULL) {
    return NULL;
  }
  struct Node* i = NULL;
  struct Node* j = NULL;
  int temp;
  for(i=head;i!=NULL;i=i->next) {
    for(j=head;j!=NULL;j=j->next) {
      if(i->data < j->data) {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
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
  printf("NULL\n");
}

void main() {
  struct Node* head = NULL;
  head = insertAtEnd(head,6);
  head = insertAtEnd(head,1);
  head = insertAtEnd(head,13);
  head = insertAtEnd(head,27);
  head = insertAtEnd(head,20);

  sortedList(head);
  printf("Sorted List:");
  display(head);
}