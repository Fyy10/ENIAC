#include<stdio.h>
int main()
{
	int k,i=0;
	double sn=0;
	scanf("%d",&k);
	while(sn<=k)
	{
		++i;
		sn+=1.0/i;
	}
	printf("%d\n",i);
	return 0;
}
