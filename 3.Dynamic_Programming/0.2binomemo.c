#include<stdio.h>


	int a[100][100];

int binomial(int n, int k)
{

	if(k==0 || n==k)
	{
		return a[n][k]=1;
	}
	if(n<k)
	{
		return a[n][k]=0;
	}
	if(a[n][k]!=-1)
	{
		return a[n][k];
	}
	else
	{
		return a[n][k]= (binomial(n-1,k-1)+binomial(n-1,k));
	}
}

int main()
{
	int n,k;
	printf("enter value of n:");
	scanf("%d",&n);
	printf("enter value of k:");
	scanf("%d",&k);
	int i,j;
	a[n][k];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=k;j++)
		{
			a[i][j]=-1;
		}
	}
	printf("\n%d\n",binomial(n,k));
	return 0;
}
