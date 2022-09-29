#include <stdio.h>

int binomial(int n, int k)
{
	int a[100][100], i, j;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			if (i == j || j == 0)
			{
				a[i][j] = 1;
			}

			else if (j>i)
			{
				a[i][j] = 0;
			}
			
			else
			{
				a[i][j] = (binomial(i - 1, j - 1) + binomial(i - 1, j));
			}
		}
	}
	return a[n][k];
}
int main()
{
	int n, k;
	printf("enter values of n and k in the form of nCk:");
	scanf("%d%d", &n, &k);
	printf("%d", binomial(n, k));
	return 0;
}

