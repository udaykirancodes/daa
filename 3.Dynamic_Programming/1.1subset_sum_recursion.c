// A recursive solution for subset sum problem
#include <stdio.h>
#include <stdbool.h>

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

// Driver code
int main()
{
	int set[] = {3, 34, 4, 7, 5};
	int sum = 6;
	int n = sizeof(set) / sizeof(set[0]);
	if (ss(set, n, sum) == 1)
		printf("\nFound a subset with given sum\n");
	else
		printf("\nNo subset with given sum\n");
	return 0;
}
