#include <stdio.h>

int binary_Search(int a[], int left, int right, int key) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (a[mid] == key)
        return mid;
    else if (key < a[mid])
        return binary_Search(a, left, mid - 1, key); 
    else
        return binary_Search(a, mid + 1, right, key);
}

void main() {
    int n, i, key, pos=-1;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter array elements (sorted): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter the key: ");
    scanf("%d", &key);
    pos = binary_Search(a, 0, n - 1, key);
    if (pos != -1)
        printf("Key found at index = %d\n", pos);
    else
        printf("Key not found!\n");
}