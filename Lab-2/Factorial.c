#include<stdio.h>
void main() {
  int n,i,res=1;
  printf("Enter a number=");
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    res = res*i;
  }
  printf("Factorial=%d",res);
}