// #include<stdio.h>
// void main() {
//   int i=1,n,count=0;
//   printf("Enter a number:");
//   scanf("%d",&n);

//   for(i=1;i<=n;i++) {
//      if(n%i==0) {
//        count++;
//      }
//   }

//   if(count==2)
//     printf("Prime number");
//   else
//     printf("Not Prime number");
// }

#include<stdio.h>
void main() {
  int n,i,count=0;
  printf("Enter a number:");
  scanf("%d",&n);
  for(i=1;i<=n;i++) {
    if(n%i==0) {
      count++;
    }
  }
  if(count==2) {
    printf("Prime Number");
  }
  else {
    printf("Not Prime Number");
  }
}