#include<stdio.h>
#include<math.h>
int gcd(long int a,long int b);
int xa,ya;
int main()
{
	long int x,y,m,n,l;
	int gab;
	while(scanf("%ld%ld%ld%ld%ld",&x,&y,&m,&n,&l)==5)
	{
		gab=gcd(n-m,l);
		if((x-y)%gab==0)
		{
			xa*=(x-y)/gab;
			while(xa<0)
				xa+=l*abs(x-y)/gab;
			xa%=l*abs(x-y)/gab;
			printf("%d\n",xa);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
int gcd(long int a,long int b)
{
	int t,d;
	if(b==0)
	{
		xa=1;
		ya=0;
		return a;
	}
	d=gcd(b,a%b);
	t=xa;
	xa=ya;
	ya=t-(a/b)*ya;
	return d;
}
