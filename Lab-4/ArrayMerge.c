#include<stdio.h>
void main() {
  int x,y,i,j,merge[500];
  printf("Enter the size of an array-1:");
  scanf("%d",&x);
  int a[x];
  printf("Enter array-1 elements:");
  for(i=0;i<x;i++) {
    scanf("%d",&a[i]);
  }
  printf("Enter the size of an array-2:");
  scanf("%d",&y);
  int b[y];
  printf("Enter array-2 elements:");
  for(i=0;i<y;i++) {
    scanf("%d",&b[i]);
  }
  for(i=0;i<x;i++) {
    merge[i] = a[i];
  }
  for(j=0;j<y;j++) {
    merge[i+j] = b[j];
  }
  printf("After merged array:");
    for(i = 0; i < x + y; i++) {
        printf("%d ",merge[i]);
    }
}