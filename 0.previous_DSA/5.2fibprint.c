#include<stdio.h>

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibo(n-1)+fibo(n-2);
    }
    
}
int main()
{
    int n;
    printf("\nEnter the no. of fibonacci to be printed\t:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf(" %d ",fibo(i));
    }
    
}