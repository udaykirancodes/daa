// A Dynamic Programming solution
// for coin change problem
#include <stdio.h>

int min( int a, int b)
{
    if (a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}


int coinchange(int coinset[], int n, int sum)
{
    // The value of dp[i][j] will be true if
    // there is a dp of coinset[0..j-1] with sum
    // equal to i
    int dp[n + 1][sum + 1];
    
    // Fill the dp table in bottom up manner

    for (int i = 0; i <= n; i++)
    {       
            dp[i][0] = 0;
    }
    
    for (int j = 0; j <= sum; j++)
    {
        dp[0][j] = __INT_MAX__-1;
    }
    

    for (int j = 1; j <= sum; j++)
    {
        if (j%coinset[0] == 0)
        {
            dp[1][j] = j/coinset[0];  
        }
        else
        dp[1][j] = __INT_MAX__-1;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            
            if (j >= coinset[i - 1])
                dp[i][j] = min( dp[i - 1 ][j] , dp[i][j - coinset[i - 1]]+1);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // uncomment this code to print table
    for (int i = 0; i <= n; i++)
    {
    for (int j = 0; j <= sum; j++)
        printf (" %d ", dp[i][j]);
    printf("\n");
    }

    return dp[n][sum];
}

// Driver code
int main()
{
    int coinset[] = {5,10,13,3,40};
    int sum = 100;
    int n = sizeof(coinset) / sizeof(coinset[0]);

    int a = coinchange(coinset, n, sum);
    printf("\nmin #coins for given sum  = %d\n",a);
    
    return 0;
}

//answer is 11 

// 10
// 5 5
// 5 2 2 1
// 5 2 1 1 1
// 5 1 1 1 1 1
// 2 2 2 2 2
// 2 2 2 2 1 1
// 2 2 2 1 1 1 1 
// 2 2 1 1 1 1 1 1 
// 2 1 1 1 1 1 1 1 1 
// 1 1 1 1 1 1 1 1 1 1

