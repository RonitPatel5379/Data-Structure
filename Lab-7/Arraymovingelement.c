#include <stdio.h>

#define SIZE 100

void main() {
    int T;
    printf("Enter the testcases:");
    scanf("%d", &T);
    while (T--) {
        int N;
        printf("Enter the length of an array:");
        scanf("%d", &N);
        int A[SIZE], S[SIZE], top = -1;
        printf("Enter array elemnts:");
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        int next = 1; 
        int index = 0;
        while (index < N || top >= 0) {
            if (top >= 0 && S[top] == next) {
                top--;
                next++;
            } else if (index < N) {
                S[++top] = A[index++];
            } else {
                break;
            }
        }
        if (next == N + 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}