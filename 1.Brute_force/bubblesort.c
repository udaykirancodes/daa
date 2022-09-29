#include <stdio.h>

void printArray(int n , int arr[])
{
    printf("\n Ascending Order : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d " ,arr[i]);
    }
    printf("\n");
    printf("\n Descending Order : ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d " ,arr[n-i-1]);
    }
    printf("\n");
}

void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bs(int n , int arr[])
{
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (arr[j+1]<arr[j])    // change < to > to get descending order
            {
                swap(&arr[j+1],&arr[j]);
            }
            
        }
        
    }
    
}


int main()
{
    int arr[] = {14,36,7, 243,259,60};
    int n = sizeof(arr)/sizeof(arr[1]/* can also use int in place of arr[1]*/);
    bs(n ,arr);
    printf("The sorted array is :");
    printArray(n, arr);
    return 0;
}