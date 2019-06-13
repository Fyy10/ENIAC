#include<stdio.h>
#include<string.h>
int findkey(char title[],char key[]);
int main()
{
	int t,n,ans;
	char key[25],title[105],tmp[105];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d\n",&n);
		key[0]=' ';
		key[1]='\0';
		scanf("%s",tmp);
		getchar();
		strcat(key,tmp);
		key[strlen(key)+1]='\0';
		key[strlen(key)]=' ';
		ans=0;
		while(n--)
		{
			title[0]=' ';
			title[1]='\0';
			gets(tmp);
			strcat(title,tmp);
			title[strlen(title)+1]='\0';
			title[strlen(title)]=' ';
			if(findkey(title,key))
				++ans;
		}
		if(ans==0)
			printf("Do not find\n\n");
		else
			printf("%d\n\n",ans);
	}
	return 0;
}
int findkey(char title[],char key[])
{
	int i=0,j,found;
	while(i+strlen(key)<=strlen(title))
	{
		if(title[i]==key[0])
		{
			found=1;
			for(j=i;j<i+strlen(key);++j)
			{
				if(title[j]!=key[j-i])
					found=0;
			}
		}
		if(found)
			break;
		++i;
	}
	return found;
}
