#include<stdio.h>
#define INF 100000000
int main()
{
	int minl,maxl,t,n,i,gap;
	int stone[100001];
	scanf("%d",&t);
	while(t--)
	{
		minl=0;
		maxl=INF;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d",&stone[i]);
		}
		for(i=0;i<n-1;++i)
		{
			scanf("%d",&gap);
			if(minl<(stone[i]+gap))
				minl=stone[i]+gap;
			if(maxl>(stone[i]+gap+stone[i+1]))
				maxl=stone[i]+gap+stone[i+1];
		}
		if(minl<=maxl)
			printf("%.2f\n",(double)minl);
		else
			printf("impossible\n");
	}
	return 0;
}
