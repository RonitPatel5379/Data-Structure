#include<stdio.h>
void main() {
    int year;
    printf("Enter a year");
    scanf("%d",&year);
    if((year%4==0) && (year!=100) || (year%400==0)) {
        printf("Leap year");
    }
    else {
        printf("Not Leap year");
    }
}