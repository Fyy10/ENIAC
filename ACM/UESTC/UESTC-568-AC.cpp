#include<stdio.h>
int main()
{
	int n,s,t,i,j,ans;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&s,&t);
		ans=0;
		while(s<t)
		{
			if(3*s<=t)
			{
				ans+=s;
				s*=3;
				s++;
			}
			else
			{
				if(t-s<=2)
				{
					if(t-s==2)
						ans++;
				}
				else
				{
					ans++;
					ans+=(t-s-2)/2;
				}
				break;
			}
		}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
