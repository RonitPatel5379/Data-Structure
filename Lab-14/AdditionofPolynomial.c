#include<stdio.h>
#include<stdlib.h>

struct Node {
  int coeff;
  int pow;
  struct Node* next;
};

struct Node* insertAtEnd(struct Node* head,int coeff,int pow) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->coeff = coeff;
  newNode->pow = pow;
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

struct Node* addPolynomial(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->pow == p2->pow) {
            result = insertAtEnd(result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow) {
            result = insertAtEnd(result, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            result = insertAtEnd(result, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        result = insertAtEnd(result, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        result = insertAtEnd(result, p2->coeff, p2->pow);
        p2 = p2->next;
    }
    return result;
}

void display(struct Node* poly) {
  while(poly!=NULL) {
    printf("%dx^%d",poly->coeff,poly->pow);
    poly = poly->next;
    if(poly!=NULL) {
      printf("+");
    }
  }
}

void main() {
  struct Node* p1 = NULL;
  struct Node* p2 = NULL;
  struct Node* result = NULL;
  p1 = insertAtEnd(p1,1,5);
  p1 = insertAtEnd(p1,3,4);
  p1 = insertAtEnd(p1,4,3);
  p1 = insertAtEnd(p1,2,2);
  p1 = insertAtEnd(p1,1,1);
  p1 = insertAtEnd(p1,2,0);
  p2 = insertAtEnd(p2,4,4);
  p2 = insertAtEnd(p2,5,3);
  p2 = insertAtEnd(p2,10,2);
  p2 = insertAtEnd(p2,5,1);
  p2 = insertAtEnd(p2,4,0);

  printf("Polynomial 1:");
  display(p1);
  printf("\nPolynomial 2:");
  display(p2);

  result = addPolynomial(p1,p2);
  printf("\nresultant polynomial:");
  display(result);
}