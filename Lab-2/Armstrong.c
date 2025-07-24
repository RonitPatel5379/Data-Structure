#include<stdio.h>
void main() {
  int n,rem,res=0;
  printf("Enter a number :");
  scanf("%d",&n);
  int num=n;
  while(num!=0) {
    rem = num%10;
    res = res + rem*rem*rem*rem;
    num=num/10;
  }
  if(res==n) {
    printf("Armstrong Number");
  }
  else {
    printf("Not Armstrong Number");
  }
}