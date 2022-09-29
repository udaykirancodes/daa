#include<stdio.h>
#define max 10

int visited[max] = {0};
int a[max][max];

void dfs(int v,int n)
{
	visited[v]=1;  
	for(int i=0;i<n;i++)
	{
		if(a[v][i] && !visited[i])
		{
			printf("\n%c ---> %c\n",v+65,i+65);
			dfs(i,n);
		}
	}
}

int main()
{
	int n;
	printf("\nEnter the no of vertices in the graph\t:");
	scanf("%d",&n);
	
	printf("\nEnter the adjacency matrics of graph\n ");

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("\nEnter the element in row %d and column %d :\t ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	dfs(0,n);
	return 0;
}


