#include <stdio.h>
#include <string.h>

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}
void sort(double value[], double weight[], double ratio[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n ; j++)
        {
            if ( (ratio[i]) < (ratio[j]) ) 
            {
                swap(&value[i], &value[j]);
                swap(&ratio[i], &ratio[j]);
                swap(&weight[i], &weight[j]);
            }
        }
    }
}

double knapsack(double value[], double weight[], int capacity, double ratio[], int n)
{
    double result = 0.0;
    for (int i = 0; i < n; i++)
    {
        // If adding Item won't overflow, add it completely
        if (weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            result = result + value[i];
        }

        // If we can't add current Item, add fractional part
        // of it
        else
        {
            result = result + value[i] * (capacity / weight[i]);
            break;
        }
    }

    // Returning final value
    return result;
}
int main()
{
    int n, capacity;
    double maxvalue;

    printf("\nEnter the capacity of knapsack :\t");
    scanf("%d", &capacity);
    // printf("\nThe capacity of knapsack is :\t%d",capacity);

    printf("\nEnter the no.of items  :\t");
    scanf("%d", &n);
    // printf("\nThe no.of items is  :\t%d",n);

    double value[n], weight[n];
    double ratio[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the value and weight of item %d :\t", i + 1);
        scanf("%le", &value[i]);
        scanf("%le", &weight[i]);
        ratio[i] = ( value[i] / weight[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nThe value , weight and ratio of item %d is (%.2f,%.2f,%.2f) :\t", i + 1, value[i], weight[i], ratio[i]);
    }
    

    printf("\n\n\n After Sorting: ");

    sort(value, weight, ratio, n);

    for (int i = 0; i < n; i++)
    {
        printf("\nThe value , weight and ratio of item %d is (%.2f,%.2f,%.2f) :\t", i + 1, value[i], weight[i], ratio[i]);
    }

    maxvalue = knapsack(value, weight, capacity, ratio, n);
    printf(" \n\nThe max value of the bag  \t %.2f\n\n", maxvalue);

    return 0;
}