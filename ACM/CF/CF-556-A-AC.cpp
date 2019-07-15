#include<stdio.h>
int main()
{
	int max=0,min=10000,n,m,r,tmp;
	scanf("%d %d %d",&n,&m,&r);
	while(n--)
	{
		scanf("%d",&tmp);
		if(tmp<min)
			min=tmp;
	}
	while(m--)
	{
		scanf("%d",&tmp);
		if(tmp>max)
			max=tmp;
	}
	if(min<max)
	{
		r=r%min+r/min*max;
	}
	printf("%d",r);
	return 0;
}
