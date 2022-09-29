#include<stdio.h>
#include<string.h>

int main()
{
    int m,n,j,f = -1;
    char main [100];
    char search [15];


    printf("\nEnter the  main string : ");
    gets(main);
    //printf("The main string is : %s \n",main);

    printf("\nEnter the  search string : ");
    gets(search);
    //printf("The search string is :%s\n",search);

    m=strlen(main);
    //printf("main string length : %d\n",m);
    n=strlen(search);
    //printf("search string length : %d\n",n);

    for (int i = 0; i < m-n; i++)
    {
        for (  j = i; j < i+n; j++)
        {
            if (main[j]!=search[j-i])
            {
                break;
            }
            
        }
            if (j == i+n)
            {
                f = i;
                break;
            }
        
    }

    if ( f== -1)
    {
        printf("\nString not found\n");
    }
    else
    {
        printf("\nString  starts at %dth & ends at %dth  positions \n",f+1,f+n);
    }
    
    
    return 0;
}