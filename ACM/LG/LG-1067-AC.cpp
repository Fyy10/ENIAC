#include<stdio.h>
#include<string.h>
int main()
{
	char tmp[10],ax[10000];
	int n,a;
	memset(ax,'\0',sizeof(ax));
	scanf("%d",&n);
	while(n>=0)
	{
		memset(tmp,'\0',sizeof(tmp));
		scanf("%d",&a);
		if(a)
		{
			if(n)
			{
				if(ax[0]=='\0')
				{
					if(a==1)
						sprintf(tmp,"x^%d",n);
					else
					{
						if(a==-1)
							sprintf(tmp,"-x^%d",n);
						else
							sprintf(tmp,"%dx^%d",a,n);
					}
					if(n==1)
						tmp[strlen(tmp)-2]='\0';
				}
				else
				{
					if(a==1)
						sprintf(tmp,"+x^%d",n);
					else
						if(a==-1)
							sprintf(tmp,"-x^%d",n);
						else
							sprintf(tmp,"%+dx^%d",a,n);
					if(n==1)
						tmp[strlen(tmp)-2]='\0';
				}
			}
			else
				sprintf(tmp,"%+d",a);
		}
		strcat(ax,tmp);
		--n;
	}
	puts(ax);
	return 0;
}
