#include<stdio.h>
void main() {
    int n;
    printf("Enter a Number=");
    scanf("%d",&n);
    if(n%2==0) {
        printf("The Number is Even");
    }
    else {
        printf("The Number is Odd");
    }
}