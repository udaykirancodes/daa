// sqrt not working
#include<stdio.h>
//#include<conio.h>
#include<math.h>


int main()
{
    int n;
    printf("\nEnter the no of points to be entered\t :");
    scanf("%d",&n);
    int x[n],y[n];
    double k[n][n];
    double min = 10000;
    int idxx;
    int idxy;

    for ( int i = 0; i < n; i++)
    {
        printf("\nEnter the x,y coordinates of %d\t :",i+1);
        scanf("%d",&x[i]);
        scanf("%d",&y[i]);
    }

    // for ( int i = 0; i < n; i++)
    // {
    //     printf("\nThe x,y coordinates of %d are (%d,%d) :",i+1,x[i],y[i]);
    // }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
            {
                k[i][j]=(((x[j]-x[i])*(x[j]-x[i]))+((y[j]-y[i])*(y[j]-y[i])));

                
                if (min>k[i][j])
                {   
                    min = k[i][j];
                    idxx=i;
                    idxy=j;
                }
                printf("Distance b/w point %d & %d = %.2f\n",i+1,j+1,k[i][j]);
            
            }
            

    }
    
    printf("\nThe points(%d,%d) and (%d,%d) are the closest pair with distance : %.2f:",x[idxx],y[idxx],x[idxy],y[idxy],min);
    
    
    return 0;
}