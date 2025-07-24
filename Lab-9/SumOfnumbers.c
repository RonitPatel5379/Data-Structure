#include<stdio.h>
#include<stdlib.h>

void main() {
  int *iptr,i,n,sum = 0;
  
  printf("Enter the number:");
  scanf("%d",&n);

  iptr = (int *)(malloc(n*sizeof(int)));

  for(i=0;i<=n;i++) {
    sum = sum + *(iptr+i);
  }
  printf("%d",sum);
}