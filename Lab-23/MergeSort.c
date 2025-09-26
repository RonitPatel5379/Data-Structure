#include<stdio.h>

void merge(int a[],int low,int mid,int high) {
  int h,i,j,k;
  int b[high-low+1];
  h=low,i=low,j=mid+1;
  while(h<=mid && j<=high) {
    if(a[h]<=a[j]) {
      b[i-low]=a[h];
      h++;
    }
    else {
      b[i-low] = a[j];
      j++;
    }
    i++;
  }
  if(h>mid) {
    for(k=j;k<=high;k++) {
      b[i-low] = a[k];
      i++;
    }
  }
  else {
    for(k=h;k<=mid;k++) {
      b[i-low] = a[k];
      i++;
    }
  }
  for(k=low;k<=high;k++) {
    a[k] = b[k-low];
  }
}

void mergeSort(int a[],int low,int high) {
  if(low < high) {
    int mid = low + (high-low)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}

void main() {
  int n,i;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  mergeSort(a,0,n-1);
  for(i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
}