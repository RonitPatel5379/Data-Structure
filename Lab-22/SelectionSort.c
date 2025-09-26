#include<stdio.h>
void main() {
  int n,i,j,min_index,temp;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++) {
    min_index=i;
    for(j=i+1;j<n;j++) {
      if(a[j] < a[min_index]) {
        min_index = j;
      }
    }
    temp = a[min_index];
    a[min_index] = a[i];  
    a[i] = temp;
  }
  printf("Sorted Array=");
  for(i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
}