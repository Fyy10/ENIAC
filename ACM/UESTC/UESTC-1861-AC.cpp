#include<stdio.h>
long int power(int o);
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		i=1;
		scanf("%d",&n);
		while(power(i)<(long int)n)
			++i;
		if(n==1)
			i=0;
		printf("%d\n",i);
	}
	return 0;
}
long int power(int o)
{
	long int ans=1;
	int j;
	for(j=1;j<=o;++j)
		ans=ans<<1;
	return ans;
}
