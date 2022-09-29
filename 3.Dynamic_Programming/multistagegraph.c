#include <stdio.h>
#define INF 99999
#define n 8

//int path[n];

int main()
{
    int i, j ,dist[n];
    // printf("\nEnter the no of nodes\n");
    // scanf("%d",&n);

    int a[n][n] = {
        {INF, 1, 2, 5, INF, INF, INF, INF},
        {INF, INF, INF, INF, 4, 11, INF, INF},
        {INF, INF, INF, INF, 9, 5, 16, INF},
        {INF, INF, INF, INF, INF, INF, 2, INF},
        {INF, INF, INF, INF, INF, INF, INF, 18},
        {INF, INF, INF, INF, INF, INF, INF, 13},
        {INF, INF, INF, INF, INF, INF, INF, 2},
        {INF, INF, INF, INF, INF, INF, INF, INF},
    };

    dist[n - 1] = 0;

    for (i = n - 2; i >= 0; i--)
    {
        dist[i] = INF;

        for (j = i; j < n; j++)
        {
            if (a[i][j] == INF)
                continue;

            else if (a[i][j] + dist[j] < dist[i])
                dist[i] = a[i][j] + dist[j];
                //path[i] = j;

        }
    }
    printf("\n\nThe minimum = %d \n\n ", dist[0]);

    printf("\ndistance array is:\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }

    // printf("\npath is:\n ");
    // for (int i = n; i > 0; i--)
    // {
    //     printf("%c --> ", path[i]+65);
    // }
}
