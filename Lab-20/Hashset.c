#include <stdio.h>
#include <stdlib.h>

#define n 10
int hash[n];

int hashFun(int key)
{
    return key % n;
}

void initialize()
{
    for (int i = 0; i < n; i++)
    {
        hash[i] = -1;
    }
}

void insert(int key)
{
    int index = hashFun(key);

    if (hash[index] == key)
    {
        printf("Already Key %d is Present !!\n", key);
        return;
    }
    else if (hash[index] == -1)
    {
        hash[index] = key;
        return;
    }
    else
    {
        // Linear Probing;
        for (int probe = 1; probe < n; probe++)
        {
            int i = (index + probe) % n;

            if (hash[i] == key)
            {
                printf("Already Key %d is Present !!\n", key);
                return;
            }
            else if (hash[i] == -1)
            {
                hash[i] = key;
                return;
            }
        }

        printf("Hash Table is  Full !!\n");
    }
}

int search(int key)
{
    int index = hashFun(key);

    if (hash[index] == key)
    {
        return index;
    }
    else
    {
        for (int prob = 1; prob < n; prob++)
        {
            int i = (index + prob) % n;

            if (hash[i] == key)
            {
                return i;
            }
            else if (hash[i] == -1)
            {
                break;
            }
        }

        printf("\n\nKey %d is not available in the hashTable !!\n\n", key);
        return -1;
    }
}

void deleteKey(int key)
{
    int index = hashFun(key);

    if (hash[index] == key)
    {
        hash[index] = -2;   // mark to deleted
        printf("Key %d deleted successfully.\n", key);
        return;
    }
    else
    {
        for (int prob = 1; prob < n; prob++)
        {
            int i = (index + prob) % n;

            if (hash[i] == key)
            {
                hash[i] = -2; 
                printf("Key %d deleted successfully.\n", key);
                return;
            }
            else if (hash[i] == -1)
            {
                break;  // empty so Not to delete
            }
        }
    }
    printf("Key %d not found in hash table.\n", key);
}


void display()
{
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
    insert(23);

    display();

    printf("Index = %d\n", search(3));
    printf("index = %d\n", search(23));
    printf("\n");

    deleteKey(23);
    deleteKey(4);

    display();

    return 0;
}