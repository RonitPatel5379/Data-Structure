#include <stdio.h>
#include <stdlib.h>

int exists(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) return 1;
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int W[N + 1];
        for (int i = 1; i <= N; i++) {
            scanf("%d", &W[i]);
        }

        int uniqueKeys[N];
        int count = 0;

        for (int i = 1; i <= N; i++) {
            int key = i - W[i];
            if (!exists(uniqueKeys, count, key)) {
                uniqueKeys[count++] = key;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}