#include<stdio.h>
int main()
{
	int n=1;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		printf("%d\n",8*n-4);
	}
	return 0;
}
