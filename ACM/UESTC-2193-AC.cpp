#include<stdio.h>
#include<string.h>
int main()
{
	char s[13][5]={"\0","Jan:","Feb:","Mar:","Apr:","May:","Jun:","Jul:","Aug:","Sep:","Oct:","Nov:","Dec:"};
	int n,birth[13],tmp,i,j,t=0;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		t++;
		memset(birth,0,sizeof(birth));
		for(i=1;i<=n;i++)
		{
			scanf("%*d %d %*d",&tmp);
			birth[tmp]++;
		}
		printf("Case #%d:\n",t);
		for(i=1;i<=12;i++)
		{
			printf("%s",s[i]);
			for(j=0;j<birth[i];j++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
