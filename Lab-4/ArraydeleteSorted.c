#include<stdio.h>
void main() {
  int n,num,i,position;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  printf("Enter the deleted number:");
  scanf("%d",&num);
  for(i=0;i<n;i++) {
    if(a[i]==num) {
      break;
    }
  }
  position=i;
  for(i=position;i<n;i++) {
    a[i] = a[i+1];
  }
  printf("Array After Insertion:");
  for(i=0;i<n-1;i++) { 
    printf("%d ",a[i]);
  }
}