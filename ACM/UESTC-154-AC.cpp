#include<stdio.h>
int main()
{
	int n,l,v,i,pos;
	char gender,dir;
	double maxt,sumd;
	while(scanf("%d%d%d",&n,&l,&v)==3)
	{
		if(n==0&&l==0&&v==0)
			break;
		maxt=0;
		sumd=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %c %c",&pos,&gender,&dir);
			if(dir=='W')
			{
				sumd+=pos;
				if((double)pos/v>maxt)
					maxt=(double)pos/v;
			}
			else
			{
				sumd+=l-pos;
				if((double)(l-pos)/v>maxt)
					maxt=(double)(l-pos)/v;
			}
		}
		printf("%.2lf %.2lf\n",maxt,sumd);
	}
	return 0;
}
