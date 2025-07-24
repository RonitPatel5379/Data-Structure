#include<stdio.h>
void main() {
    int radius;
    float area;

    printf("Enter Radius=");
    scanf("%d",&radius);
    area = 3.14*radius*radius;
    printf("Area : %f",area);
}