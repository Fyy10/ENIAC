#include<stdio.h>
#include<string.h>
#define N 400002
int prime[N];
int isprime[N];
void getprime();
int main()
{
	int pos=0,n,i,n1=0,n2=0,tmp,sum=0;
	getprime();
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&tmp);
		if(tmp==1)
			n1++;
		else
			n2++;
	}
	if(n==1)
	{
		if(n1)
			printf("%d ",1);
		if(n2)
			printf("%d ",2);
		return 0;
	}
	if(n2>0)
	{
		printf("%d ",2);
		sum+=2;
		n2--;
		n--;
	}
	else
	{
		printf("%d %d ",1,1);
		sum+=2;
		n1-=2;
		n-=2;
	}
	while(n)
	{
		if(prime[pos+1]-prime[pos]>=2)
		{
			if(n2>0)
			{
				printf("%d ",2);
				sum+=2;
				if(sum==prime[pos+1])
					pos++;
				n2--;
				n--;
			}
			else
			{
				printf("%d ",1);
				sum+=1;
				if(sum==prime[pos+1])
					pos++;
				n1--;
				n--;
			}
		}
		else
		{
			if(n1>0)
			{
				printf("%d ",1);
				sum+=1;
				if(sum==prime[pos+1])
					pos++;
				n1--;
				n--;
			}
			else
			{
				printf("%d ",2);
				sum+=2;
				if(sum==prime[pos+1])
					pos++;
				n2--;
				n--;
			}
		}
	}
	return 0;
}
void getprime()
{
	int pos=0,i,j;
	memset(isprime,1,sizeof(prime));
	for(i=2;i<N;i++)
	{
		if(isprime[i])
			prime[pos++]=i;
		for(j=0;j<pos&&i*prime[j]<N;j++)
		{
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}
	}
}
