#include <stdio.h>


int isSubsetSum(int set[], int n, int sum)
{
    int subset[n + 1][sum + 1];
    

    for (int i = 0; i <= n; i++)
        subset[i][0] = 1;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1 ][j] + subset[ i - 1 /*this -one*/ ][j - set[i - 1]];
        /*if we remove -1 then it will function like unbounded knapsack but 
        the no of repeatations of each element ids limited to total no of elements available in 
        this case 6 so it will be found if -1 is removed*/
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
    int set[] = {2,3,5,6,8,10};
    int sum = 10;
    int n = sizeof(set) / sizeof(set[0]);

    int a = isSubsetSum(set, n, sum);
    printf("\n#Subsets with given sum  = %d\n",a);
    
    return 0;
}

// bounded case answer is 3
// 2 3 5
// 2 8
// 10

// unbounded case answer is 7 remove -1 for this case

// above 3 and
// 2 2 2 2 2 
// 5 5
// 2 2 6
// 2 2 3 3 

