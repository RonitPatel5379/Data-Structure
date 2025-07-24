#include<stdio.h>
void main() {
  int i,pow,base,res=1;
  printf("Enter a base & power=");
  scanf("%d %d",&base,&pow);

  for(i=1;i<=pow;i++) {
    res = res * base ;
  }
  printf("ANS=%d",res);
}