#include<stdio.h>
#include<math.h>
int gcd(int a,int b);
int main()
{
	int x,y,m,n,l,ans;
	while(scanf("%d%d%d%d%d",&x,&y,&m,&n,&l)==5)
	{ 
		if(abs(x-y)%gcd(abs(m-n),l)==0)
		{
			ans=0;
			while(1)
			{
				ans+=1;
				if(((x-y)+(m-n)*ans)%l==0)
					break;
			}
			printf("%d\n",ans);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
int gcd(int a,int b)
{
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	return a;
}
