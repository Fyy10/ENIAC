#include<stdio.h>
int digitsum(int m);
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		if((i+digitsum(i))==n)
			break;
	}
	if(i>n)
		printf("%d\n",0);
	else
		printf("%d\n",i);
	return 0;
}
int digitsum(int m)
{
	int sum;
	sum=m/100000+m%100000/10000+m%10000/1000+m%1000/100+m%100/10+m%10;
	return sum;
}
