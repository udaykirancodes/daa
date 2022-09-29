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

    printf("enter 1 if there is an edge \nenter 0 if no edge\n\n");
    for (int i = 0; i < n; i++)
    {
        distance[i] = max;
        visit[i] = 0;
        for (int j = i; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else
            {
                printf("%c---%c  ", i + 65, j + 65);
                scanf("%d", &adj[i][j]);
                adj[j][i] = adj[i][j];
            }
        }
    }

    printf("\nenter the weights of edges: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                adj[i][j] = 0;
            else if (adj[i][j] == 0)
                adj[i][j] = max;
            else
            {
                printf("%c---%c  ", i + 65, j + 65);
                scanf("%d", &adj[i][j]);
            }
            adj[j][i] = adj[i][j];
        }
    }

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
