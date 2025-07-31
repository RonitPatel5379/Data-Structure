#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* insertAtEnd(struct Node* head,int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL) {
    return newNode;
  }
  struct Node* temp = head;
  while(temp->next!=NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

struct Node* swapNodes(struct Node* head) {
    if (head == NULL || head->next == NULL){
        return head;
    }
    struct Node* prev = NULL;
    struct Node* temp = head;
    head = head->next;

    while (temp != NULL && temp->next != NULL) {
        struct Node* third = temp->next->next;
        struct Node* second = temp->next;
        second->next = temp;
        temp->next = third;
        if (prev != NULL) {
            prev->next = second;
        }
        prev = temp;
        temp = third;
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
  head = insertAtEnd(head,1);
  head = insertAtEnd(head,2);
  head = insertAtEnd(head,3);
  head = insertAtEnd(head,4);
  head = insertAtEnd(head,5);
  head = insertAtEnd(head,6);

  head = swapNodes(head);
  printf("Swap Nodes:");
  display(head);
}

/*struct Node* swapNodes(struct Node* head) {
      if(head==null) {
          return head;
      }
      struct Node* prev = null;
      struct Node* temp = head;
      head = head->next;
      while(temp!=null && temp->next!=null) {
          struct Node* second = temp->next;
          struct Node* third = temp->next->next;
          second->next = temp;
          temp->next = third;
          if(prev!=null) {
              prev->next = second;
          }
          prev = temp;
          temp = third;
      }
  }      
*/