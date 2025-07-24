#include<stdio.h>
void main() {
  int n,i;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  printf("Elements are=",i);
  for(i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
}