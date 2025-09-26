#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int stack[100];
int top = -1;

void push(int c){
    stack[++top] = c;
}

int pop(){
    return stack[top--];
}

void evalPostfix(char postfix[]){
    int i;
    for(i=0; i<strlen(postfix);i++){
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');
        else{
            // int num = 0;
            // char c;
            // num = num*10 + (c - '0');
            int operand2 = pop();
            int operand1 = pop();
            switch(postfix[i]) {
                case '+':
                push(operand1 + operand2);
                break;
                case '-':
                push(operand1 - operand2);
                break;
                case '*':
                push(operand1 * operand2);
                break;
                case '/':
                push(operand1 / operand2);
                break;
                case '^':
                push(pow(operand1,operand2));
            }
        }
    }
}

void main(){
    char postfix[100];
    printf("Enter a posfix expression :");
    scanf("%s",postfix);
    evalPostfix(postfix);
    printf("postfix value: %d",pop());
}