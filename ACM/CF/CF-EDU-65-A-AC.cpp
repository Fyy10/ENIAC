#include<stdio.h>
int main()
{
	int t,n,i,pos,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		pos=-1;
		for(i=0;i<n;i++)
		{
			scanf("%1d",&tmp);
			if(tmp==8&&pos<0)
				pos=i;
		}
		if(n-pos>=11&&pos>=0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
