#include <stdio.h>
#define max 1000
#define size 10

int visit[size];
int distance[size];
int adj[size][size];

int find_min(int n)
{
    int i, temp = max, flag;
    for (i = 0; i < n; i++)
    {
        if (distance[i] < temp && visit[i] != 1)
        {
            temp = distance[i];
            flag = i;
        }
    }

    return flag;
}
int dj(int n)
{
    int i, j, index;
    for (i = 0; i < n; i++)
    {
        index = find_min(n);
        visit[index] = 1;
        for (j = 0; j < n; j++)
        {
            if (adj[index][j] != max && visit[j] != 1)
            {
                if (distance[j] > adj[index][j] + distance[index])
                {
                    distance[j] = adj[index][j] + distance[index];
                }
            }
        }
    }
}

int main()
{
    int n;
    printf("enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        distance[i] = max;
        visit[i] = 0;
    printf("\n");
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&adj[i][j]);
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == -1)
            {
                adj[i][j] = max;
            }
        }
        
    }

    // adj[n][n] = { {0, 50, 45, 10, max, max} 
    //             {1, 0, 50, 45, 10, max, max},
    //             {max, 0, 10, 15, max, max},
    //             {max, max, 0, max, 30, max},
    //             {10, max, max, 0, 15, max},
    //             {max, 20, 35, max, 0, max},
    //             {max, max, max, max, 3, 0} };

    distance[0] = 0;

    printf("\n\n");

    printf("\nThe printing adjacency matrix as MST  is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", adj[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");

    // printf("\nthe distance array before prims algorithm is :  ");
    // for (int i = 0; i < n; i++)
    // {
    // 	printf("%d  ", distance[i]);
    // }
    // printf("\n\n");

    // printf("\n\n");

    // function call dijstra_algorithem
    dj(n);

    printf("\n\n");
    printf("\nthe distance array is :   ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", distance[i]);
    }

    printf("\n\n");
}
