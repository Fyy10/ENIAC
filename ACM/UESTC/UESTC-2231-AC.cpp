#include<stdio.h>
int main()
{
	int n,a[1001],i;
	while(scanf("%d",&n)==1)
	{
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int d=a[n]-a[n-1];
		for(i=n-1;i>0;i--)
			if(a[i+1]-a[i]!=d)
				break;
		printf("%d\n",i+1);
	}
	return 0;
}
