#include<stdio.h>
void main() {
  int n,i,j;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array Elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++) {
    for(j=i+1;j<n;j++) {
      if(a[i]==a[j]) {
        printf("Array Contains Duplicate Number");
      }
    }
  }
  printf("Arry Contains Not Duplicate Number");
}