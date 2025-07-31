#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtHead(struct Node* head,int data){
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
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
  }
  return head;
}

struct Node* insertAtEnd(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(head==NULL){
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

struct Node* insertAt(struct Node* head,int idx,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  if(idx==0) {
    return insertAtHead(head,data);
  }
  struct Node* temp = head;
  int count = 0;
  while(count < idx-1 && temp->next!=head) {
    temp = temp->next;
    count++;
  }
  newNode->next = temp->next;
  temp->next = newNode;
  return head; 
}

struct Node* deleteAtHead(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
    // return NULL;
  }
  else if(head->next==head) {
    free(head);
    // return NULL;
  }
    struct Node* temp = head;
    struct Node* ptr = NULL;
    while(temp->next!=head) {
      temp = temp->next;
    }
    head = head->next;
    temp->next = head;
    free(ptr);
    return head;
}

struct Node* deleteAtEnd(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
  }
  else if(head->next==head) {
    free(head);
  }
  else {
    struct Node* temp = head;
    struct Node* ptr = NULL;
    while(temp->next!=head) {
      ptr  = temp;
      temp = temp->next;
    }
    ptr->next = head;
    free(temp);
  }
  return head;
}

struct Node* deleteAt(struct Node* head,int idx) {
  if(idx==0) {
    return deleteAtHead(head);
  }
  struct Node* temp = head;
  int count = 0;
  while(count<idx-1 && temp!=NULL)  {
    temp = temp->next;
    count++;
  }
  struct Node* ptr = temp->next;
  temp->next = ptr->next;
  free(ptr);
  return head;
}

void display(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
    return;
  }
  struct Node* temp = head;
  while(temp->next!=head) {
    printf("%d -> ",temp->data);
    temp = temp->next;
  }
  // printf("%d -> ",temp->data);
}

void main() {
  struct Node* head = NULL;
  // head = insertAtHead(head,10);
  // head = insertAtHead(head,20);
  // head = insertAtHead(head,30);
  head = insertAtEnd(head,10);
  head = insertAtEnd(head,20);
  head = insertAtEnd(head,30);
  // head = insertAt(head,1,15);
  // head = deleteAtHead(head);
  // head = deleteAtEnd(head);
  head = deleteAt(head,1);
  printf("Circular Linked List:");
  display(head);
}