#include<stdio.h>
void main()
{
    int n,i,j,k;
    printf("Enter the value of n:");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0||j==i)
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(k=0;k<n-i-1;k++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}