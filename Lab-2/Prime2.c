#include<stdio.h>
void main() {
  int i,j,start,end,count;
  printf("Enter the intervals : ");
  scanf("%d %d",&start,&end);
  printf("Prime Numbers=",i);
  for(i=start;i<=end;i++) {
    count=0;
    for(j=1;j<=i;j++) {
      if(i%j==0) {
        count++;
      }
    }
     if(count==2)
     printf("%d ",i);
  }
}