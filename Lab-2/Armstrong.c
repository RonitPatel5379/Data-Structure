#include <stdio.h>
#include <math.h>

void main() {
    int num, originalNum, remainder, n = 0;
    float result = 0.0;
    printf("Enter a number: ");
    scanf("%d", &num);
    originalNum = num;
    while (originalNum != 0) {
        originalNum /= 10;
        n++;
    }
    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }
    if ((int)result == num)
        printf("Armstrong Number.");
    else
        printf("Not Armstrong Number.");
}
