#include <stdio.h>
#define max 1000

int f_parent(int i, int p[])
{
	while (p[i] != -1)
	{
		i = p[i];
	}
	return i;
}

int kruskull(int k, int parent[], int source[], int destiny[], int wt[])
{
	int i, mst = 0;
	for (i = 0; i < k; i++)
	{
		if (f_parent(source[i], parent) != f_parent(destiny[i], parent))
		{
			parent[f_parent(destiny[i], parent)] = source[i];
			mst = mst + wt[i];
		}
	}
	return mst;
}
int main()
{
	int n, i, j, k = 0;
	printf("enter no of nodes in a graph: ");
	scanf("%d", &n);
	int a[n][n];
	printf("\nenter 1 if node \nenter 0 if no node\n");
	printf("\nenter the nodes:\n");
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (i == j)
				a[i][j] = 0;
			else
			{
				k++;
				printf("%c--%c  ", i+65, j+65);
				scanf("%d", &a[i][j]);
			}
			a[j][i] = a[i][j];
		}
	}
	int source[k], destiny[k], wt[k], parent[k];
	k = 0;
	printf("enter the edge values: \n");
	for (i = 0; i < n; i++)
	{
		parent[i] = -1;
		for (j = i + 1; j < n; j++)
		{
			if (a[i][j] == 1)
			{
				printf("%c--%c  ", i+65, j+65);
				scanf("%d", &a[i][j]);
				source[k] = i;
				destiny[k] = j;
				wt[k] = a[i][j];
				k++;
			}
			else
				a[i][j] = max;
			a[j][i] = a[i][j];
		}
	}
	// sorting the edges according to the edges
	printf("\n\n");
	// for (i = 0; i < k; i++)
	// {
	// 	printf("%c %c %d   ", source[i]+65, destiny[i]+65, wt[i]);
	// }
	int temp1, temp2, temp3;
	for (i = 0; i < k; i++)
	{
		for (j = i + 1; j < k; j++)
		{
			if (wt[i] > wt[j])
			{
				temp1 = source[i];
				temp2 = destiny[i];
				temp3 = wt[i];
				source[i] = source[j];
				destiny[i] = destiny[j];
				wt[i] = wt[j];
				source[j] = temp1;
				destiny[j] = temp2;
				wt[j] = temp3;
			}
		}
	}
	printf("\nminimum value of graph==%d", kruskull(k, parent, source, destiny, wt));
	printf("\n");
	printf("MST nodes: \n\n");
	for (i = 1; i < n; i++)
	{
		printf("\n\t%c-->%c  ", parent[i]+65,i+65);
	}
}
