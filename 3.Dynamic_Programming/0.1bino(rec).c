#include <stdio.h>
int binomial(n, k)
{
	if (k == 0 || n == k)
	{
		return 1;
	}

	else if (k>n)
	{
		return 0;
	}
	

	else
	{
		return (binomial(n - 1, k - 1) + binomial(n - 1, k));
	}
}
int main()
{
	int n, k;
	printf("enter values of n and k in the form of nCk:");
	scanf("%d%d", &n, &k);
	printf("%d", binomial(n, k));
	return 0;
}
