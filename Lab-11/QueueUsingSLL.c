#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node* head = NULL;

struct Node* enqueue(struct Node* head,int data) {
  struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
  if(head == NULL){
    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    return;
  }
  newNode->data = data;
  newNode->next = NULL;

  struct Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

struct Node* dequeue(struct Node *head)
{
  // struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
  if (head == NULL)
  {
    printf("List is empty.");
  }
  else
  {
    struct Node* temp = head;
    head = head->next;
    free(temp);
  }
  return head;
}

void display(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
}

void main()
{

  head = enqueue(head,10);
  head = enqueue(head,20);
  head = enqueue(head,30);
  head = enqueue(head,40);
  head = dequeue(head);
  printf("Queue Using SLL:");
  display(head);
}
