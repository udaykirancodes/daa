#include<stdio.h>
int a[20];
int p=1;
int main()
{
	int i,j,k,n,min,temp;
	printf("enter the size of the array:");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(k=0;k<n;k++)
	{
		scanf("%d",&a[k]);
	}
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
			
		}
		printf("\nThe Sorted Elements after %d pass\n",p++);
		for(k=0;k<n;k++)
		printf("%d",a[k]);
	}
	printf("\nSorted elements:");
	for(k=0;k<n;k++)
	printf("%d",a[k]);
}
