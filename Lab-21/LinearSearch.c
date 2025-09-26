#include<stdio.h>
void main() {
    int n,i,key,pos=-1;
    printf("Enter the size of an array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    printf("Enter the key:");
    scanf("%d",&key);
    for(i=0;i<n;i++) {
        if(a[i]==key) {
            pos = i;
        }
    }
    if(pos != -1)
        printf("Key found at index = %d\n", pos);
    else
        printf("Key not found!\n");
}