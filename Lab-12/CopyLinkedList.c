#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* copyList(struct node *first,struct node *newFirst){
    if (first==NULL)
    {
        printf("List is empty.");
        return first;
    }
    newFirst=first;
    struct node *temp=first->next;
    struct node *newNode=newFirst;

    while(temp!=NULL)
    {
        struct node *copyNode=temp;
        newNode->next=copyNode;
        temp=temp->next;
        newNode=newNode->next;
    }
    return newFirst;
}

void display(struct node *first){
    struct node *temp=first;
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

void displayNew(struct node *newFirst){
    struct node *temp=newFirst;
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
}

void main(){
struct node *first=(struct node *)malloc(sizeof(struct node));
struct node *second=(struct node *)malloc(sizeof(struct node));
struct node *third=(struct node *)malloc(sizeof(struct node));
struct node *newFirst=NULL;
    first->data = 10;
    first->next = second;

    second->data = 20; 
    second->next = third;

    third->data = 30; 
    third->next = NULL;

    printf("original list ");
    display(first);
    newFirst=copyList(first,newFirst);
    printf("\ncopy list ");
    displayNew(newFirst);
}