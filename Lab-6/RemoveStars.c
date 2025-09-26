#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char ch) {
    if (top < SIZE - 1) {
        stack[++top] = ch;
    }
}

void pop() {
    if (top >= 0) {
        top--;
    }
}

void removeStars(char s[], char output[]) {
    top = -1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '*') {
            pop();
        } else {
            push(s[i]);
        }
    }
    for (int i = 0; i <= top; i++) {
        output[i] = stack[i];
    }
    output[top + 1] = '\0';
}

void main() {
    char s[SIZE], finalOutput[SIZE];
    printf("Enter input string: ");
    scanf("%s",s);
    removeStars(s, finalOutput);
    printf("Output: \"%s\"\n", finalOutput);
}