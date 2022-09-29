#include <stdio.h>
#include<string.h>
#define x 100

int a[x];

int fibo(int n)
{

    if (a[n] != -1)
    {
        return a[n];
    }
    if (n == 0 || n == 1)
    {
        return a[n] = n;
    }
    else
    {
        return a[n] = fibo(n - 1) + fibo(n - 2);
    }
}

int main()
{
    int n;
    memset(a,-1,sizeof(a));
    
    printf("\nEnter the position of fibonacci u need\t:");
    scanf("%d", &n);
    printf("\n result is %d\n", fibo(n));
}