#include <stdio.h>
int front = -1;
int rear = -1;
int arr[5];

void ENQUEUE(int num)
{
    if (rear >= 4)
    {
        printf("queue overflow");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    arr[++rear] = num;
    printf("%d", rear);
}

void ENQUEUE_FRONT(int num)
{
    if (front==0)
    {
        printf("queue overflow");
        return;
    }
    if (front==-1)
    {
        front=0;
        rear=0;
    }
    else{
        front--;
    }
    arr[front]=num;
}

void DEQUEUE()
{
    if (front > rear || front == -1)
    {
        printf("queue undeflow");
        return;
    }
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void DEQUEUE_REAR()
{
    if (rear==-1)
    {
        printf("queue underflow");
        return;
    }
    if (front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        rear--;
    }
    
}

void DISPLAY()
{
    if (front == -1)
    {
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
}

void main()
{
    int choice, num;
    while (1)
    {
        printf("Enter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Value:");
            scanf("%d", &num);
            ENQUEUE(num);
            break;

        case 2:
            DEQUEUE();
            break;

        case 4:
            DEQUEUE_REAR();
            break;

        case 5:
            printf("Enter Value:");
            scanf("%d", &num);
            ENQUEUE_FRONT(num);
            break;

        case 6:
            DISPLAY();
            break;

        default:
            break;
        }
    }
}