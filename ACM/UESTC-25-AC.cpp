#include<stdio.h>
#include<string.h>
int isgood(char *s);
int main()
{
	char s[102],tmp[101];
	int n,m,score[2][9],score0,score1,i;
	while(1)
	{
		scanf("%d",&n);
		getchar();
		if(n==0)
			break;
		memset(score,-1,sizeof(score));
		score0=0;
		score1=0;
		for(i=0;i<n;++i)
		{
			s[0]='A';
			s[1]='\0';
			gets(tmp);
			strcat(s,tmp);
			if(isgood(s))
			{
				if(i%2==0)
				{
					++score0;
					score[0][i/2]=1;
				}
				else
				{
					++score1;
					score[1][i/2]=1;
				}
			}
			else
			{
				if(i%2==0)
				{
					score[0][i/2]=0;
				}
				else
				{
					score[1][i/2]=0;
				}
			}
		}
		if(n%2==1)
			m=n/2+1;
		else
			m=n/2;
		for(i=1;i<=m;++i)
			printf("%d ",i);
		printf("Score\n");
		for(i=0;i<m;++i)
		{
			if(score[0][i]==-1)
				printf("- ");
			if(score[0][i]==0)
				printf("X ");
			if(score[0][i]==1)
				printf("O ");
		}
		printf("%d\n",score0);
		for(i=0;i<m;++i)
		{
			if(score[1][i]==-1)
				printf("- ");
			if(score[1][i]==0)
				printf("X ");
			if(score[1][i]==1)
				printf("O ");
		}
		printf("%d\n",score1);
	}
	return 0;
}
int isgood(char *s)
{
	int judge=1;
	if(s[strlen(s)-5]!=' ')
		judge=0;
	if(s[strlen(s)-6]!='o')
		judge=0;
	if(s[strlen(s)-7]!='n')
		judge=0;
	if(s[strlen(s)-8]!=' ')
		judge=0;
	return !judge;
}
