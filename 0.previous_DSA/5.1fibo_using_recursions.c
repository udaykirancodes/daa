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
    printf("\nEnter the position of fibonacci u need\t:");
    scanf("%d",&n);
    printf("\n result is %d\n",fibo(n));
}