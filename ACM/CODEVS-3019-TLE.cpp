#include<stdio.h>
int main()
{
	long long int i=0,n=0,k;
	scanf("%d",&k);
	while(n<k)
	{
		++i;
		if(i%3==2&&i%5==3&&i%7==2)
			++n;
	}
	printf("%d",i);
	return 0;
}
