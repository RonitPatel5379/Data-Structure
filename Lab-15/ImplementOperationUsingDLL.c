#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* insertAtHead(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = head;
  newNode->prev = NULL;
  if(head!=NULL) {
    head->prev = newNode;
  }
  head = newNode;
  return head;
}

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

struct Node* insertAt(struct Node* head,int idx,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  if(idx==0) {
    return insertAtHead(head,data);
  }
  struct Node* temp = head;
  int count = 0;
    for(int i=0;count<idx-1 && temp!=NULL;i++) {
      temp = temp->next;
      count++;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL) {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

struct Node* deleteAtHead(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
    return NULL;
  }
  struct Node* temp = head;
  head = head->next;
  if(head!=NULL) {
    head->prev = NULL;
  }
  free(temp);
  return head;
}

struct Node* deleteAtEnd(struct Node* head) {
  if(head==NULL) {
    printf("List is empty.");
    return NULL;
  }
  if(head->next==NULL) {
    free(head);
    return NULL;
  }
  struct Node* temp = head;
  while(temp->next!=NULL) {
    temp = temp->next;
  }
  temp->prev->next = NULL;
  free(temp);
  return head;
}

struct Node* deleteAt(struct Node* head,int idx) {
  if(head==NULL) {
    printf("List is empty.");
    return NULL;
  }
  if(idx==0) {
    return deleteAtHead(head);
  }
  struct Node* temp = head;
  int count = 0;
  for(int i=0;count <= idx-1 && temp!=NULL;i++) {
    temp = temp->next;
    count++;
  }
   if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
   }
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
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
  // head = insertAtHead(head,10);
  // head = insertAtHead(head,20);
  // head = insertAtHead(head,30);
  // head = insertAtHead(head,40);
  head = insertAtEnd(head,10);
  head = insertAtEnd(head,20);
  head = insertAtEnd(head,30);
  head = insertAtEnd(head,40);
  // head = insertAt(head,1,15);
  // head = deleteAtHead(head);
  // head = deleteAtEnd(head);
  head = deleteAt(head,1);
  display(head);
}