#include<stdio.h>
#include<string.h>
int findnum(int mem[],int x);
int f(int x);
int main()
{
	int ans=0,i,mem[100],n,p=0;
	memset(mem,-1,sizeof(mem));
	scanf("%d",&n);
	mem[p]=n;
	p++;
	ans++;
	for(i=1;i<=10000;i++)
	{
		n=f(n);
		if(!findnum(mem,n))
		{
			mem[p]=n;
			p++;
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
int findnum(int mem[],int x)
{
	int i;
	for(i=0;i<100;i++)
		if(mem[i]==x)
			return 1;
	return 0;
}
int f(int x)
{
	while(1)
	{
		if((x+1)%10)
			return x+1;
		else
			x/=10;
	}
}
