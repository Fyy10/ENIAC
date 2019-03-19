#include<stdio.h>
#include<string.h>
int main()
{
	char c[1001];
	int t,judge,i,j;
	scanf("%d\n",&t);
	while(t--)
	{
		judge=1;
		scanf("%s",c);
		for(i=0;i<strlen(c)-1;++i)
		{
			if(c[i]=='(')
				for(j=i+1;j<strlen(c);++j)
					if(c[j]==')')
					{
						c[i]=' ';
						c[j]=' ';
						break;
					}
		}
		for(i=0;i<strlen(c);++i)
			if(c[i]=='('||c[i]==')')
				judge=0;
		if(judge)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
