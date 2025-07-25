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

struct Node* mergeSortedList(struct Node* head1, struct Node* head2) {
    struct Node temp;
    struct Node* tail = &temp;
    temp.next = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    if(head1!=NULL) {
          tail->next = head1;
        }
        else {
          tail->next = head2;
        }
     return temp.next;
  }

void display(struct Node* head) {
    struct Node* temp = head;
    while(temp!=NULL) {
      printf("%d -> ",temp->data);
      temp = temp->next;
    }
}

void main() {
  struct Node* head1 = NULL;
  struct Node* head2 = NULL;

  head1 = insertAtEnd(head1,1);
  head1 = insertAtEnd(head1,3);
  head1 = insertAtEnd(head1,5);

  head2 = insertAtEnd(head2,2);
  head2 = insertAtEnd(head2,4);
  head2 = insertAtEnd(head2,6);
  struct Node* mergedList = mergeSortedList(head1, head2);
  printf("Merged List:");
  display(mergedList);
}