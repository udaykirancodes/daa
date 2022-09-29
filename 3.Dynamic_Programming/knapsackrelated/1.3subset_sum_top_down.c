// A Dynamic Programming solution
// for subset sum problem
#include <stdio.h>
#include <stdbool.h>

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];
    
    // Fill the subset table in bottom up manner
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                subset[i][j] = false;
            }
            if (j == 0)
            {
                subset[i][j] = true;
            }
            
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1 ][j] || subset[ i - 1/*this -one*/ ][j - set[i - 1]];
        /*if we remove -1 then it will function like unbounded knapsack but 
        the no of repeatations of each element ids limited to total no of elements available in 
        this case 5 so it will be found if -1 is removed*/
        }
    }

    /* // uncomment this code to print table
    for (int i = 0; i <= n; i++)
    {
    for (int j = 0; j <= sum; j++)
        printf ("%4d", subset[i][j]);
    printf("\n");
    }*/

    return subset[n][sum];
}

// Driver code
int main()
{
    int set[] = {21,11,34,23,1};
    int sum = 5;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, n, sum) == true)
        printf("\nFound a subset with given sum\n");
    else
        printf("\nNo subset with given sum\n");
    return 0;
}
// This code is contributed by Arjun Tyagi.
