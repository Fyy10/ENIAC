#include<stdio.h>
#include<stack>
int main()
{
	int n,i,out[1001],pa,pb;
	while(scanf("%d",&n)==1)
	{
		if(n==0)
			break;
		while(1)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%d",&out[i]);
				if(out[1]==0)
					break;
			}
			if(out[1]==0)
				break;
			pa=1;
			pb=1;
			std::stack<int> s;
			while(1)
			{
				while(!s.empty()&&s.top()==out[pb])
				{
					pb++;
					s.pop();
				}
				if(pa==n+1||pb==n+1)
					break;
				if(out[pb]==pa)
				{
					pa++;
					pb++;
				}
				else
				{
					s.push(pa);
					pa++;
				}
			}
			if(pa==pb&&!s.size())
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}