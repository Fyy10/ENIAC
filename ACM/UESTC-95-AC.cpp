#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,r,max,min,v[100],s,i;
	double pi=acos(-1.0);
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		min=20;
		s=0;
		scanf("%d %d",&n,&r);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			if(v[i]>=max)
				max=v[i];
			if(v[i]<=min)
				min=v[i];
		}
		v[0]=v[n];
		for(i=1;i<=n;i++)
		{
			if(v[i-1]>v[i])
				s+=v[i-1]-v[i];
		}
		if(max==min)
			printf("Inf\n");
		else
			printf("%.3lf\n",2*pi*r/(double)s);
	}
	return 0;
}
