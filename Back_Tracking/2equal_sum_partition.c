// A recursive solution for subset sum problem
#include <stdio.h>

int ss(int set[], int n, int sum)
{
	if (sum == 0)
		return 1;

	if (n == 0)
		return 0;

	if (set[n - 1] > sum)
		return ss(set, n - 1, sum);

	return ss(set, n - 1, sum) || ss(set, n - 1, sum - set[n - 1]);
}

int tsum( int set[],int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + set[i];
    }

    return s;
}

// Driver code
int main()
{
	int set[] = {3, 4, 4, 5};
	int n = sizeof(set) / sizeof(set[0]);

    int fsum = tsum(set,n);

    if (fsum%2 == 0)
    {
        int sum = fsum/2;
        fsum = ss(set, n, sum);
    }
    else
    {
		printf("\nNo equal subset with given sum\n");
        return 0;
    }
    
    

	if (fsum == 1)
		printf("\nFound a equal subset with given sum\n");
	else
		printf("\nNo equal subset with given sum\n");
	return 0;
}
