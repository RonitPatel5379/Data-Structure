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
  int max=a[0];
  int min=a[0];
  int maxIndex=0,minIndex=0;
  for(i=0;i<n;i++) {
    if(a[i]>max) {
      max=a[i];
      maxIndex=i;
    }
    else if(a[i]<min) {
      min=a[i];
      minIndex=i;
    }
  }
  printf("Longest Position=%d %d\n",max,maxIndex);
  printf("Smallest Position=%d %d",min,minIndex);
}