#include<stdio.h>
void main() {
  int n,i,j,sum=0;
  printf("Enter a number:");
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    for(j=1;j<=i;j++) {
      sum = sum + j;
    }
  }
  printf("Sum=%d",sum);
}