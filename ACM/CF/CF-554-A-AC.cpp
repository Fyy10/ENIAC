#include<stdio.h>
int main()
{
	int m,n,odda=0,oddb=0,evena=0,evenb=0,tmp;
	scanf("%d %d\n",&n,&m);
	while(n--)
	{
		scanf("%d",&tmp);
		if(tmp%2)
			++odda;
		else
			++evena;
	}
	while(m--)
	{
		scanf("%d",&tmp);
		if(tmp%2)
			++oddb;
		else
			++evenb;
	}
	printf("%d",(odda<evenb?odda:evenb)+(evena<oddb?evena:oddb));
	return 0;
}
