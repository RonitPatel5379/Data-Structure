#include<stdio.h>
#include<stdlib.h>

void main() {
  int *ptr,i,n,j,temp;

  printf("Enter the size of an array:");
  scanf("%d",&n);

  ptr = (int *)(malloc(n*sizeof(int)));

  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",ptr+i);
  }
  for(i=0;i<n-1;i++) {
    for(j=i+1;j<n;j++) {
      if(*(ptr + i)>*(ptr + j)) {
        temp = *(ptr + i);
        *(ptr + i) = *(ptr + j);
        *(ptr + j) = temp;
      }
    }
  }
  for(i=0;i<n;i++) {
    printf("%d ",*(ptr + i));
  }
}