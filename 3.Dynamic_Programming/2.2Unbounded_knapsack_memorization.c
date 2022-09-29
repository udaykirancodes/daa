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
int knapsack(int value[],int weight[],int capacity,int n)
{
    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }

    if (n == 0 || capacity == 0 )
    {
        
        return dp[n][capacity] = 0;
    }

    
    
    if (weight[n-1]<= capacity )
    {
        return dp[n][capacity] = max( value[n-1]+knapsack(value,weight,capacity-weight[n-1],n),knapsack(value,weight,capacity,n-1));
    }
    else
    {
        return dp[n][capacity] = knapsack(value,weight,capacity,n-1);
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
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            printf("%d  ",dp[i][j]);
        }
        printf("\n");
    }
    
    maxvalue = knapsack(value,weight,capacity,n);
    printf(" \n\nThe value of the bag  \t %d\n\n",maxvalue);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            printf("%d  ",dp[i][j]);
        }
        printf("\n");
    }
    return 0;
}