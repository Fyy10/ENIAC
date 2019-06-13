#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,nw;
	char sentence[202];
	scanf("%d\n",&n);
	while(n--)
	{
		gets(sentence);
		sentence[strlen(sentence)+1]='\0';
		sentence[strlen(sentence)]=' ';
		nw=0;
		for(i=0;i+1<strlen(sentence);++i)
		{
			if(sentence[i]!=' '&&sentence[i+1]==' ')
				++nw;
		}
		printf("%d\n",nw);
	}
	return 0;
}
