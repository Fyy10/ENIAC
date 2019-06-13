#include<stdio.h>
int main()
{
	int i,a[4],max=0;
	for(i=0;i<4;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	for(i=0;i<4;++i)
	{
		if(a[i]!=max)
		{
			printf("%d ",max-a[i]);
		}
	}
	return 0;
}
