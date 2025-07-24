#include<stdio.h>
void main() {
  int seconds,minutes,hours;
  printf("Enter the number of seconds=");
  scanf("%d",&seconds);
  hours=seconds/3600;
  seconds=seconds%3600;
  minutes=seconds/60;
  seconds=seconds%60;
  printf("%d:%d:%d",hours,minutes,seconds);
}