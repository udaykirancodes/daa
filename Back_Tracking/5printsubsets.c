// A recursive solution for subset sum problem
#include <stdio.h>
#include<string.h>
int n;
int rsum = 0;
int count = 0;

void PrintArray(int set[],int x[])
{
    for ( int i = 0; i < n; i++)
    {
        if (x[i])
            printf(" %d ",set[i]);
        else
            printf(" _ ");

    }
        printf("\n");
    
}
int ss(int set[], int n, int sum,int x[])
{
	if (sum == 0)
    {
        count++;
		PrintArray(set,x);
        return 0;
    }
    
	if (n == 0 || rsum < sum)
		return 0;

	if (set[n - 1] <= sum)
		{
            x[n-1] = 1;
            ss(set,n-1,sum - set[n-1],x);
        }

	x[n-1] = 0;
    ss(set, n - 1, sum,x);
}

// Driver code
int main()
{
	int set[] = {2,3,5,8,10};
	int sum = 10;
    

    n = sizeof(set) / sizeof(set[0]);
    int x[]={0,0,0,0,0};
    PrintArray(set,x);
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        rsum += set[i]; 
    }

	ss(set, n, sum,x);

		printf("\n#subset with given sum: %d %d\n",count,rsum);

	return 0;
}
