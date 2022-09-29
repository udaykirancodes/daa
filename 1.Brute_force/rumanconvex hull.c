#include<stdio.h>
int main()
{
	int i,j,n,k,a,b,c,nn,np;
	printf("enter no.of points:");
	scanf("%d",&n);
	int x[100],y[100];
	for(i=0;i<n;i++)
	{
		printf("%d::",i+1);
		scanf("%d %d",&x[i],&y[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			a=y[i]-y[j];                    //a=y1-y2
			b=x[j]-x[i];                   //b=x2-x1
			c=y[j]*x[i]-y[i]*x[j];        //c=y2x1-y1x2
			for(k=0;k<n;k++)
			{
				int l;
				l=a*x[k]+b*y[k]+c;
				if(l>0)
				{
					np++;
				}
				else if(l<0)
				{
					nn++;
				}
			}
			if(np==0 || nn==0)
			{
				printf("points are (%d,%d),(%d,%d)",x[i],y[i],x[j],y[j]);
			}
		}
	}
}
//int main()
//{
//    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
//                      {3, 0}, {0, 0}, {3, 3}};
//    int n = sizeof(points)/sizeof(points[0]);
//    convexhull(points, n);
//    return 0;
//}
