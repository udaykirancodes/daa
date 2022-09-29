#include <stdio.h>
int partition(int[], int, int);
int quicksort(int[], int, int);
int a[10], n, p = 1;
int main()
{
	int i;
	printf("Enter the size of the array:");
	scanf("%d", &n);
	printf("Enter the elements:\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	printf("\nThe Sorted array is\n");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
}


int partition(int a[], int lb, int ub)
{
	int pivot, start, end, temp;
	pivot = lb;
	start = lb;
	end = ub;
	while (start < end)
	{
		while (a[start] <= a[pivot])
		{
			start++;
		}
		while (a[end] > a[pivot])
		{
			end--;
		}
		if (start < end)
		{
			temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	temp = a[pivot];
	a[pivot] = a[end];
	a[end]=temp;
	int i;
	printf("\nThe Sorted array after %d PASS\n", p++);
	for (i = 0; i < n; i++)
	{
		printf(" %d ", a[i]);
	}
	return end;
}


int quicksort(int a[], int lb, int ub)
{
	int loc;
	if (lb < ub)
	{
		loc = partition(a, lb, ub);
		quicksort(a, lb, loc - 1);
		quicksort(a, loc + 1, ub);
	}
}
