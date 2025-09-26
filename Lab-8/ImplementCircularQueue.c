#include<stdio.h>
int front=-1;
int rear=-1;
int arr[5];

void INSERT(int num){
    if (rear==5)
    {
       rear=0;
    }
    else{
        rear++;
    }
    if (front==rear)
    {
        printf("queue overflow");
        return;
    }
    if(front==-1){
        front=0;
    }
    arr[++rear]=num;
}

void DELETE(){
    if (front>rear||front==-1)
    {
        printf("queue undeflow");
        return;
    }
    front++;
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    if (front==5)
    {
        front=0;
    }
    else
    {
        front++;
    }
}

void DISPLAY(){
    if (front==-1)
    {
        return;
    }
    
    for (int i = front; i <= rear; i++)
    {
       printf("%d ",arr[i]);
    }
    
}

void main(){
    int choice,num;
    while (1)
    {
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter Value:");
        scanf("%d",&num);
        INSERT(num);
            break;
        
            case 2:
        DELETE();
            break;

            case 3:
        DISPLAY();
            break;

        default:
            break;
        }
    }
}