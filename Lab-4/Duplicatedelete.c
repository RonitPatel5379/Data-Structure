#include<stdio.h>
void main() {
  int n,i,j,k;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++) {
    for(j=i+1;j<n;j++) {
      if(a[i]==a[j]) {
        for(k=j;k<n-1;k++)  {
          a[k] = a[k+1];
        }
        n--;
      }
    }
  }
  printf("After removing duplicates:");
  for(i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
}