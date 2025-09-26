#include <stdio.h>
#include <string.h>

#define SIZE 1000

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top < SIZE - 1)
        stack[++top] = value;
}

int pop() {
    if (top >= 0)
        return stack[top--];
    return 0;
}

int getEncodedOpen(char ch) {
    if (ch == '(') return 1;
    if (ch == '{') return 2;
    if (ch == '[') return 3;
    return 0;
}

int getEncodedClose(char ch) {
    if (ch == ')') return 1;
    if (ch == '}') return 2;
    if (ch == ']') return 3;
    return 0;
}

int isBalanced(char str[]) {
    top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(getEncodedOpen(ch));
        } else if (ch == ')' || ch == '}' || ch == ']') {
            int expected = getEncodedClose(ch);
            int topVal = pop();
            if (topVal != expected) {
                return 0;
            }
        }
    }
    return top = -1;
}

void main() {
    int T;
    char str[SIZE];
    printf("No. of Testcases:");
    scanf("%d", &T);
    while (T--) {
        printf("Enter the string:");
        scanf("%s",str);
        printf("%d\n",isBalanced(str));
    }
}