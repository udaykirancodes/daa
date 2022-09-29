#include <stdio.h>
#include <string.h>

int main()
{
    int n;

    printf("\nEnter the no. of fibonacci to be printed\t:");
    scanf("%d", &n);

    int a[n];

    a[0] = 0;
    a[1] = 1;

    printf("\n Fibonacci Series is :  1,");

    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        printf(" %d, ", a[i]);

    }
}