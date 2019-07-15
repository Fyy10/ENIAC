#include<stdio.h>
#include<math.h>
int gcd(int a,int b);
int main()
{
	int t,hh,mm,up,down;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d:%d",&hh,&mm);
		hh%=12;
		up=abs(60*hh-11*mm);
		if(up>360)
			up=720-up;
		down=2;
		if(up%down==0)
			printf("%d\n",up/down);
		else
			printf("%d/%d\n",up/gcd(up,down),down/gcd(up,down));
	}
	return 0;
}
int gcd(int a,int b)
{
	while(a*b!=0)
	{
		if(a>b)
			a%=b;
		else
			b%=a;
	}
	return a+b;
}
