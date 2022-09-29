#include <stdio.h>
#include <limits.h>

int a[100][100];
int main()
{
    int n,flag = 0;
    printf("\nEnter the no. of vertices in the graph :");
    scanf("%d",&n);
    

    printf("\nEnter the 1 if link is present 0 if link is not present b/w ith and jth vertex\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        printf("\n");
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (a[i][j] != a[j][i] )
    //         {
    //             flag = 1;
    //         }
    //     }
    //     printf("\n");
    // }
    

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                    a[i][j] =(a[i][j] || ( a[i][k] && a[k][j]));
                // uncomment to see all transitions of the matrix from M^0 TO  M^n
                printf("%d ", a[i][j]);
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


    // UNCOMMENT To check if given graph is directed on undirected
    // if ( flag == 1)
    // {
    //     printf("\nDirected graph\n");
    // }
    //
    // else
    //     printf("\nUndirected graph\n");

    
}



