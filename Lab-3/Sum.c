#include<stdio.h>
void main() {
  int i,m,n,sum=0;
  printf("Enter the numbers:");
  scanf("%d %d",&m,&n);
  for(i=m;i<=n;i++) {
     sum = sum + i;
  }
  printf("Sum=%d",sum);
}