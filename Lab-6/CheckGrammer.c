// #include <stdio.h>
// #include <string.h>
// #include <stdbool.h>

// #define SIZE 100

// char stack[SIZE];
// int top = -1;

// void push(char ch) {
//     if (top < SIZE - 1) {
//         stack[++top] = ch;
//     }
// }

// char pop() {
//     if (top >= 0) {
//         return stack[top--];
//     }
// }

// bool isPalindrome(char str[]) {
//     int len = strlen(str);
//     int mid = len / 2;
//     for (int i = 0; i < mid; i++) {
//         push(str[i]);
//     }
//     int start = (len % 2 == 0) ? mid : mid + 1;
//     for (int i = start; i < len; i++) {
//         char topChar = pop();
//         if (str[i] != topChar)
//             return false;
//       }
//       return true;
// }

// void main() {
//     char *testStrings[] = {"aca", "bcbb", "abcba", "abbcbba"};
//     int n = sizeof(testStrings) / sizeof(testStrings[0]);
//     for (int i = 0; i < n; i++) {
//         top = -1;
//         printf("String: %s -> ", testStrings[i]);
//         if (isPalindrome(testStrings[i]))
//             printf("Valid (Palindrome)\n");
//         else
//             printf("Invalid (Not Palindrome)\n");
//     }
// }

#include<stdio.h>
#include<stdlib.h>

int top=-1;
char check[10];

void push(char ch){
    if(top>=10){
        printf("Stack overflow \n");
        return;
    }
    top++;
    check[top]=ch;
}

char pop(){
    if (top < 0) {
        return '\0';
    }
    return check[top--];
}

int recognize(char str[],int size){
    int i=0;
    char ch;
     while ((ch = str[i]) != '\0') {
        if (ch == 'c') {
            break;
        }
        if (ch == ' ') {
            printf("Invalid: space detected\n");
            return -1;
        }
        push(ch);
        i++;
    }
    i++;
     while (top>=0)
     {   
        ch=pop();
        if (ch!=str[i])
        {
           return 0;
        }
        i++;
     }
    if (str[i]=='\0')
    {
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    int size;
    printf("Enter size:");
    scanf("%d",&size);
    char str[size+1];
    printf("Enter string:");
    scanf("%s",str);
    int a=recognize(str,size);
    printf("%d",a);
}