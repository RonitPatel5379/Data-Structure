#include<stdio.h>
void main() {
    int year,week,days;
    printf("Enter the number of days=");
    scanf("%d",&days);
    year=days/365;
    days=days%365;
    week=days/7;
    days=days%7;
    printf("%d year,%d week,%d days",year,week,days);
}