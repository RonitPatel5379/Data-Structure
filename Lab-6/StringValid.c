// #include<stdio.h>

// void main() {
//   char str[100];
//   int countA=0,countB=0;
//   printf("Enter the String:");
//   scanf("%s",str);
//   for(int i=0;str[i]!='\0';i++) {
//     if(str[i]=='a') {
//       countA++;
//     }
//     else {
//       countB++;
//     }
//   }
//   if(countA==countB) {
//     printf("Valid String.");
//   }
//   else {
//     printf("Invalid String.");
//   }
// }

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top < SIZE - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
}

bool isPalindrome(char str[]) {
    int i = 0;
    while (str[i] == 'a') {
        push('a');
        i++;
    }
    while (str[i] == 'b') {
        if (pop() != 'a') {
            return false; 
        }
        i++; 
    }
    if (str[i] != '\0' || top != -1) {
        return false;
    }
    return true;
}

void main() {
    char str[SIZE];

    printf("Enter a string:");
    scanf("%s",str);

    if (isPalindrome(str)) {
        printf("Accepted (Palindrome)\n");
    } else {
        printf("Not Accepted (Not Palindrome)\n");
    }
}