#include <stdio.h>
#include <limits.h>
#define INF 99999

int a[100][100];
int main()
{
    int n;
    printf("\nEnter the no. of vertices in the graph :");
    scanf("%d",&n);
    

    printf("\nEnter the distances. of vertices in the graph (in case of no link enter -1)\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]  == -1)
            {
                a[i][j] = INF;
            }
            
        }
        printf("\n");
    }
    

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][k] + a[k][j] < a[i][j])
                {
                    a[i][j] = a[i][k] + a[k][j];
                }
                // uncomment to see all transitions of the matrix from M^0 TO  M^n
                //printf("%d ", a[i][j]);
            }
            printf("\n");
        }
            printf("\n");
    }
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
