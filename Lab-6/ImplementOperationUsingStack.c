#include<stdio.h>
#include<stdlib.h>

#define SIZE 100 
int stack[SIZE];   
int top = -1;

void push() {
    if (top >= SIZE - 1) {
        printf("Stack is FULL (Overflow)\n");
    } else {
        int value;
        printf("Enter value to PUSH: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Value %d pushed to stack.\n", value);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack is EMPTY (Underflow)\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is EMPTY\n");
    } else {
        printf("Stack from TOP to BOTTOM:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n",stack[i]);
        }
    }
}

void peep() {
    int pos;
    printf("Enter position from top (1 = top): ");
    scanf("%d", &pos);
    int index = top - pos + 1;
    if (index < 0 || pos <= 0) {
        printf("Invalid position!\n");
    } else {
        printf("Element at position %d from top is: %d\n", pos, stack[index]);
    }
}

void change() {
    int pos, newValue;
    printf("Enter position from top to change: ");
    scanf("%d", &pos);
    int index = top - pos + 1;
    if (index < 0 || pos <= 0) {
        printf("Invalid position!\n");
    } else {
        printf("Enter new value: ");
        scanf("%d", &newValue);
        printf("Changed %d to %d at position %d\n", stack[index], newValue, pos);
        stack[index] = newValue;
    }
}

void main() {
    int choice;
    while(choice!=6) {
        printf("\n===== STACK MENU =====\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. CHANGE\n");
        printf("6. EXIT\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: peep(); break;
            case 5: change(); break;
            case 6: printf("Exiting the program.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}