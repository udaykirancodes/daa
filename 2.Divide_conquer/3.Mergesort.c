#include<stdio.h>
void mergesort(int [],int ,int);
void merge(int [],int ,int ,int);
int a[100];
int n,p=1;
int main()
{
	int i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the Elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("\nThe Sorted Array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void mergesort(int a[],int lb,int ub)
{
	int mid,i;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
		printf("\nThe sorted array after %d PASS\n",p++);
		for(i=0;i<n;i++)
		{
			printf("%d",a[i]);
		}
	}
}
void merge(int a[],int lb,int mid,int ub)
{
	int i,j,k,b[100];
	i=lb;
	j=mid+1;
	k=lb;
	while(i<=mid && j<=ub)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
			k++;
		}
		else
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>mid)
	{
		while(j<=ub)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(k=lb;k<=ub;k++)
	{
		a[k]=b[k];
	}
}
