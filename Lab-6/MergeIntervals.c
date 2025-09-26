#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int compare(void *a,void *b) {
    int *intervalA = (int *)a;
    int *intervalB = (int *)b;
    return intervalA[0] - intervalB[0];
}

void mergeIntervals(int intervals[][2], int n) {
    if (n == 0)
        return;
        for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (intervals[j][0] > intervals[j + 1][0]) {
                int temp0 = intervals[j][0];
                int temp1 = intervals[j][1];
                intervals[j][0] = intervals[j + 1][0];
                intervals[j][1] = intervals[j + 1][1];
                intervals[j + 1][0] = temp0;
                intervals[j + 1][1] = temp1;
            }
        }
    }
    int merged[SIZE][2];
    int idx = 0;
    merged[0][0] = intervals[0][0];
    merged[0][1] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= merged[idx][1]) {
            if (intervals[i][1] > merged[idx][1])
                merged[idx][1] = intervals[i][1];
        } else {
            idx++;
            merged[idx][0] = intervals[i][0];
            merged[idx][1] = intervals[i][1];
        }
    }
    printf("Merge Intervals:");
    for (int i = 0; i <= idx; i++) {
        printf("{%d, %d} ", merged[i][0], merged[i][1]);
    }
    printf("\n");
}

void main() {
    int intervals[][2] = {{1,3},{2,4},{6,8},{9,10}};
    int n = 4;
    mergeIntervals(intervals,n);
}