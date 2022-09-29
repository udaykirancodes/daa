#include <stdio.h>

int n = 6;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int arr[], int i, int n)
{
    int sml = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (arr[sml] > arr[l] && l < n)
    {
        sml = l;
    }
    if (arr[sml] > arr[r] && r < n)
    {
        sml = r;
    }
    if (sml != i)
    {
        swap(&arr[i], &arr[sml]);
        heapify(arr, sml, n);
    }
}

void minheap(int arr[])
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

int rmv(int arr[])
{
    swap(&arr[0], &arr[n - 1]);
    n--;
    return arr[n];
}

void insert(int arr[], int x)
{
    arr[n] = x;
    n++;
    minheap(arr);
}

int OMP(int arr[])
{
    int fsum = 0;
    int sum = 0;

    minheap(arr);
    
    while (n > 1)
    {
        int l1 = rmv(arr);
        minheap(arr);
    
        int l2 = rmv(arr);
        minheap(arr);
    
        sum = l1 + l2;
        fsum += sum;
    
        insert(arr, sum);
    }
    return fsum;
}
void main()
{

    int arr[] = {1, 5, 6, 3, 2, 4};
    printf("\n\n%d\n\n", OMP(arr));
}
