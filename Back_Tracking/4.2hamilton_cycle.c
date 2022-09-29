#include <stdio.h>
int count = 0;

int fill_vertex(int k, int a[], int n, int adj[n][n])
{
	do
	{
		a[k] = (a[k] + 1) % (n + 1);
		if (a[k] == 0)
			return 0;
		if (adj[a[k - 1]][a[k]])
		{
			int flag = 0, j;
			for (j = 0; j < k; j++)
			{
				if (a[j] == a[k])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				if (k < n - 1 || k == n - 1 && adj[a[k]][a[0]])
				{
					return 0;
				}
			}
		}
	} while (1);
}
int display(int a[], int n)
{
	int i;
	count++;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n\n");
}

int hamilton_cycle(int k, int a[], int n, int adj[][n])
{
	while (1)
	{
		fill_vertex(k, a, n, adj);
		if (a[k] == 0)
			return 0;
		if (k == n - 1)
			display(a, n);
		else
			hamilton_cycle(k + 1, a, n, adj);
	}
}

int main()
{
	int n, i, j;
	printf("enter the  number of nodes:");
	scanf("%d", &n);
	int adj[n][n], a[n];
	printf("\nenter 1 if there is an edge\nenter 0 if no edge\n");
	for (i = 1; i <= n; i++)
	{
		a[i] = 0;
		for (j = i; j <= n; j++)
		{
			if (i == j)
				adj[i][j] = 0;
			else
			{
				printf("%d--%d  ", i, j);
				// printf("%c--%c  ", i+64, j+64);
				scanf("%d", &adj[i][j]);
			}
			adj[j][i] = adj[i][j];
		}
	}
	a[0] = 1;

	hamilton_cycle(1, a, n, adj);
	printf("\n\ncount = %d\n\n", count);
}
