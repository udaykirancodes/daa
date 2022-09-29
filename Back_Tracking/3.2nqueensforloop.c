//Time complexicity O(n!)
// Space complexicity O(n)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int a[10], count = 0;

int issafe(int k, int j)
{
	for (int l = 0; l < k; l++)
	{
		if (a[l] == j || abs(j - a[l]) == abs(l - k))
		{
			return 0;
		}
	}
	return 1;
}

void print(int n)
{
    int i, j;
    count++;
    printf("\n\n solution #%d:\n", count);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == j)
                printf("Q\t");
            else
                printf("*\t");
        }
        printf("\n");
    }
}

int nqueens(int k, int n)
{
	for (int j = 0; j < n; j++)
	{
		if (issafe(k, j))
		{
			a[k] = j;
			if (k == n - 1)
			{
				print(n);
			}
			else
			{
				nqueens(k + 1, n);
			}
		}
	}
}

int main()
{
	int n;
	printf("enter number of queens");
	scanf("%d", &n);
	int a[n];
	nqueens(0, n);
}
