#include<stdio.h>
#include<string.h>

int dp[100][100];


int max( int a ,int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
void knapsack(int value[],int weight[],int capacity,int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            

    if (i == 0 || j == 0 )
    {
        
        dp[i][j] = 0;
    }

    
    
    else if (weight[i-1]<= j )
    {
        dp[i][j] = max( value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
    }
    else
    {
        dp[i][j] = dp[i-1][j];
    }
    
    
        }
        
    }
    
}
int main()
{
    int n,capacity,maxvalue;
    memset(dp,-1,sizeof(dp));
    printf("\nEnter the capacity of knapsack :\t");
    scanf("%d",&capacity);
    //printf("\nThe capacity of knapsack is :\t%d",capacity);

    printf("\nEnter the no.of items  :\t");
    scanf("%d",&n);
    //printf("\nThe no.of items is  :\t%d",n);

    int value[n],weight[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the value and weight of item %d :\t",i+1);
        scanf("%d",&value[i]);
        scanf("%d",&weight[i]);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("\nThe value and weight of item %d is (%d,%d) :\t",i+1,value[i],weight[i]);
    // }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            printf(" %d  ",dp[i][j]);
        }
        printf("\n");
    }
    
    knapsack(value,weight,capacity,n);
    maxvalue = dp[n][capacity];
    printf(" \n\nThe max value of the bag  \t %d\n\n",maxvalue);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            printf(" %d  ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}