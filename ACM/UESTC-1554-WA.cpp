#include<stdio.h>
long int change(long int a,long int b);
long int max(long int a1,long int a2);
int main()
{
	long int x,y;
	scanf("%ld %ld",&x,&y);
	printf("%ld\n",change(x,y));
	return 0;
}
long int change(long int a,long int b)
{
	long int tmp;
	//if(max(a,b)<10)
	{
		tmp=max(a/10,b/10);
		a=a%10;
		b=b%10;
		tmp+=max(a/5,b/5);
		a=a%5;
		b=b%5;
		tmp+=max(a/2,b/2);
		a=a%2;
		b=b%2;
		tmp+=max(a,b);
	}
	//else
	//	tmp=max(a,b)/10+4;
	return tmp;
}
long int max(long int a1,long int a2)
{
	return a1>a2?a1:a2;
}
