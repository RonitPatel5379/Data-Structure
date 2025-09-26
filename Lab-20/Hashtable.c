#include <stdio.h>
#include <stdlib.h>

#define n 11
int hash[n];

// First hash function
int hashFun1(int key)
{
    return key % n;
}

// ???????????????????????????? What & Why & How ???/
int hashFun2(int key)
{
    return 8 - (key % 8);
}

// Initialize hash table
void initialize()
{
    for (int i = 0; i < n; i++)
    {
        hash[i] = -1;
    }
}

void insert(int key)
{
    int index1 = hashFun1(key);

    if (hash[index1] == -1)
    {
        hash[index1] = key;
        return;
    }
    else if (hash[index1] == key)
    {
        printf("Already Key %d is Present !!\n", key);
        return;
    }
    else
    {
        // Double hashing probing
        int index2 = hashFun2(key);
        for (int i = 1; i < n; i++)
        {
            int newIndex = (index1 + i * index2) % n;
            if (hash[newIndex] == -1)
            {
                hash[newIndex] = key;
                return;
            }
            else if (hash[newIndex] == key)
            {
                printf("Already Key %d is Present !!\n", key);
                return;
            }
        }

        printf("Hash Table is Full !!\n");
    }
}

// Search using double hashing
int search(int key)
{
    int index1 = hashFun1(key);

    if (hash[index1] == key)
        return index1;

    if (hash[index1] == -1)
        return -1;

    int index2 = hashFun2(key);

    for (int i = 1; i < n; i++)
    {
        int newIndex = (index1 + i * index2) % n;

        if (hash[newIndex] == key) return newIndex;

        if (hash[newIndex] == -1) break;
    }

    return -1;
}

void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d\n", i, hash[i]);
    }
}

int main()
{
    initialize();

    insert(5);
    insert(15);
    insert(25);
    insert(35);
    insert(45);
    insert(95);

    display();

    int pos = search(35);
    if (pos != -1)
        printf("\nKey 35 found at index %d\n", pos);
    else
        printf("\nKey 35 not found\n");

    pos = search(3);
    if (pos != -1)
        printf("Key 3 found at index %d\n", pos);
    else
        printf("Key 3 not found\n");

    return 0;
}
