#include<stdio.h>
int main()
{
	int a,b,i,max=0,n=0;
	for(i=1;i<=7;++i)
	{
		scanf("%d %d",&a,&b);
		if(a+b>8&&a+b>max)
		{
			n=i;
			max=a+b;
		}
	}
	printf("%d\n",n);
	return 0;
}
