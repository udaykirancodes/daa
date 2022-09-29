#include <stdio.h>
#define MAX 10

int visited[MAX] = {0};  
int a[MAX][MAX];

void breadth_first_search(int n)
    {
    int queue[n],rear = -1,front = -1,start = 0, i;
    
    queue[++rear] = start;
    visited[start] = 1;
    
    while(rear != front)
        {
        start = queue[++front];

        if(start != n)
            {
                printf("%c \t",start + 65);
                for(i = 0; i < n; i++)
    		    {
                if(a[start][i] && !visited[i])
                	{
                		queue[++rear] = i;
                		visited[i] = 1;
                	}
                   }
            }
        }
    }
int main()
{
int n;
    printf("\nEnter the no of vertices in the graph\t:");
    scanf("%d",&n);

    printf("\nEnter the adjancency matrix of the graph\n");

    for ( int i = 0; i < n; i++)
    {                      
        for ( int j = 0; j < n; j++)
    {
        printf("\nEnter the element in row %d & column %d :\t",i+1,j+1);
        scanf("%d",&a[i][j]);
    }
    }
breadth_first_search(n);
return 0;
}
