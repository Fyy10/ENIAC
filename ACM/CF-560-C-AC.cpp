#include<stdio.h>
#include<string.h>
int main()
{
	char s[200002];
	int n,i,ans=0,p=0;
	scanf("%d",&n);
	s[0]='\0';
	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&s[p]);
		if(p==0)
			p++;
		else
		{
			if(p%2)
			{
				if(s[p-1]!=s[p])
					p++;
				else
					ans++;
			}
			else
				p++;
		}
	}
	s[p]='\0';
	int len=strlen(s);
	if(len%2)
	{
		s[len-1]='\0';
		ans++;
	}
	printf("%d\n%s",ans,s);
	return 0;
}
