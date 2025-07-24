#include<stdio.h>
int factorial(int n);

void main() {
  int n;
  printf("Enter a number=");
  scanf("%d",&n);
  int f = factorial(n);
  printf("Fctorial=%d",f);
}

int factorial(int n) {
  if(n<=1) {
    return 1;
  }
  return n*factorial(n-1);
}