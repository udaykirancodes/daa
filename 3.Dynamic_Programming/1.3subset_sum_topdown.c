#include <stdio.h>
int n;



int ss(int set[], int sum)
{
    int subset[n + 1][sum + 1];
    

    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;

    for (int j = 1; j <= sum; j++)
        subset[0][j] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1 ][j] + subset[ i - 1  /*this -one*/ ][j - set[i - 1]];
        //if we remove -1 then it will function like unbounded knapsack 
            else
                subset[i][j] = subset[i - 1][j];
        }
    }

    // uncomment this code to print table
    for (int i = 0; i <= n; i++)
    {
    for (int j = 0; j <= sum; j++)
        printf (" %d ", subset[i][j]);
    printf("\n");
    }

    return subset[n][sum];
}

// Driver code
int main()
{
    int x[n];
    int set[] = {2,3,5,6,8,10,1,2};
    int sum = 10;
    n = sizeof(set) / sizeof(set[0]);

    int a = ss(set,sum);
    printf("\n#Subsets with given sum  = %d\n",a);
    
    return 0;
}

// bounded case answer is 3
// 2 3 5
// 2 8
// 10
//6,3,1
//2,2,6
//2,2,5,1
//8 2
//3 ,5 ,2

// unbounded case answer is 7 remove -1 for this case

// above 3 and
// 2 2 2 2 2 
// 5 5
// 2 2 6
// 2 2 3 3 
 