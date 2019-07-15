#include<stdio.h>
#include<math.h>
struct town
{
	int x;
	int y;
}a[100000];
int main()
{
	int n,i,j,num;
	while(scanf("%d",&n)==1)
	{
		double total=(double)n*(double)n;
		num=0;
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&a[i].x,&a[i].y);
		}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
				if(abs(a[i].x-a[j].x)==abs(a[i].y-a[j].y)&&abs(a[i].x-a[j].x)!=0)
					num++;
			}
		printf("%.6lf\n",(double)num/total);
	}
	return 0;
}
