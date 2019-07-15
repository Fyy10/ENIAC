#include<stdio.h>
int main()
{
	long int n;
	while(scanf("%ld",&n)==1)
	{
		if(n==0)
		{
			printf("no\n");
			continue;
		}
		if(n%4==2)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
