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
  printf("Enter the inserted number:");
  scanf("%d",&num);
  printf("Enter the position of inserted number:");
  scanf("%d",&position);
  for(i=n+1;i>position;i--) {
    a[i] = a[i-1];
  }
  a[position]=num;
  n++;
  printf("Array After Insertion:");
  for(i=0;i<n;i++) { 
    printf("%d ",a[i]);
  }
} 