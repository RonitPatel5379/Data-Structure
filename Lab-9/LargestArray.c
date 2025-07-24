#include<stdio.h>
#include<stdlib.h>

void main() {
  int *iptr,n,i,max;

  printf("Enter the size of an array:");
  scanf("%d",&n);
  
  iptr = (int *)(malloc(n*sizeof(int)));

  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",iptr+i);
  }
  max = *iptr;
  for(i=0;i<n;i++) {
    if(*(iptr+i) > max) {
      max = *(iptr+i);
    }
  }
  printf("%d",max);
}