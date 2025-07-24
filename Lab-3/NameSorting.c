#include <stdio.h>
#include <string.h>

int main() {
    int i, j, n;
    char names[100][100], temp[100];

    printf("Enter the number of names: ");
    scanf("%d", &n);
    getchar();  
    printf("Enter %d names:\n", n);
    for (i = 0; i < n; i++) {
        fgets(names[i], sizeof(names[i]), stdin);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    printf("\nNames in alphabetical order:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}