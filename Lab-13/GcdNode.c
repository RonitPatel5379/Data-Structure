#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// WAP to perform given operation in the linked list. There exist a Linked List. Add a node that contains the GCD of that two nodes between every pair adjacent node of Linked List.

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

int gcd(int a,int b) {
  while(b!=0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

struct Node* gcdLinked(struct Node* head) {
  struct Node* temp = head;
  while(temp!=NULL && temp->next!=NULL) {
    int g = gcd(temp->data,temp->next->data);
    struct Node* gcdNode = (struct Node*)malloc(sizeof(struct Node));
    gcdNode->data = g;
    gcdNode->next = NULL;
    gcdNode->next = temp->next;
    temp->next = gcdNode;
    temp = gcdNode->next;
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
  int data;
  head = insertAtEnd(head,18);
  head = insertAtEnd(head,6);
  head = insertAtEnd(head,10);
  head = insertAtEnd(head,3);

  gcdLinked(head);
  printf("GCD NODES:");
  display(head);
}