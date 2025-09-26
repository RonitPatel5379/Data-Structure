#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int f = 0, r = 0;

void enqueue(int y) {
    if (r >= SIZE) {
        printf("Queue Overflow\n");
        return;
    }
    queue[r++] = y;
    printf("Enqueued: %d\n", y);
}

void dequeue() {
    if (f == r) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Dequeued: %d\n", queue[f]);
    f++;
    if(f==r) {
        f = r = 0;  
    }
}

void display() {
    if (f == r) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = f; i < r; i++) {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

void main() {
    enqueue(5);
    enqueue(20);
    enqueue(80);
    enqueue(3);
    dequeue();
    display();
}