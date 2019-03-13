#include<stdio.h>
int main()
{
	long int a,b;
	while(scanf("%ld%ld",&a,&b)==2)
	{
		if(a==0&&b==0)
			break;
		printf("%d\n",b/3-(a-1)/3);
	}
	return 0;
}
