#include<stdio.h>
void main() {
  int n,i,index=-1;
  printf("Enter the size of an array:");
  scanf("%d",&n);
  int a[n];
  printf("Enter array elements:");
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }

  int n1,n2;
  printf("Enter number to be replaced:");
  scanf("%d",&n1);
  printf("Enter a new number:");
  scanf("%d",&n2);

  for(i=0;i<n;i++) {
    if(a[i]==n1) {
      a[i]=n2;
      break;
    }
  }

  if(index!=-1) {
    printf("Replaced at index=%d",index);
  }
  printf("Final array:");
  for(i=0;i<n;i++) {
    printf("%d ",a[i]);
  }
}