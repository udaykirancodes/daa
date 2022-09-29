#include<stdio.h>
#include<string.h>

int main()
{
    int m,n,j,f = -1;

    printf("\nEnter the size of main string : ");
    scanf("%d",&m);

    char main [m];
    printf("\nEnter the  main string : ");
    gets(main);
    printf("The main string is : %s \n",main);
    
    printf("\nEnter the size of search string : ");
    scanf("%d",&n);

    char search [n];
    printf("\nEnter the  search string : ");
    gets(search);
    printf("The search string is :%s\n",search);

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
        printf("\nString  starts at %d & ends at %d  indices \n",f+1,f+n);
    }
    
    
    return 0;
}