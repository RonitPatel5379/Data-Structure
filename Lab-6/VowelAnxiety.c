#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char ch) {
  return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
}

void reverseString(char str[], int index) {
    int left = 0, right = index - 1;
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void main() {
    int T;
    printf("Enter No. Testcases:");
    scanf("%d", &T);
    while (T--) {
        int N;
        printf("Enter the length of string:");
        scanf("%d", &N);
        char str[100];
        printf("Enter the string:");
        scanf("%s", str);
        for (int i = 0; i < N; i++) {
            if (isVowel(str[i])) {
                reverseString(str,i);
            }
        }
        printf("Vowel Anxiety=%s\n",str);
    }
}