#include<stdio.h>
int main()
{
	int a,b,t,i=1,ans=0;
	scanf("%d %d %d",&a,&b,&t);
	while(i*a<=t)
	{
		ans++;
		i++;
	}
	printf("%d",b*ans);
	return 0;
}
