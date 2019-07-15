#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
void printans(int s[],int k,int n);
int main()
{
	int n,k,i,s[100000];
	char tmp;
	while(scanf("%d %d",&n,&k)==2)
	{
		memset(s,0,sizeof(s));
		i=0;
		while(i<n)
		{
			tmp=getchar();
			if(tmp<='9'&&tmp>='0')
			{
				s[i]=tmp-'0';
				i++;
			}
			if(tmp<='f'&&tmp>='a')
			{
				s[i]=tmp-'a'+10;
				i++;
			}
		}
		if(k)
		{
			printans(s,k,n);
			printf("\n");
		}
	}
	return 0;
}
void printans(int s[],int k,int n)
{
	deque<int> q;
	int i;
	for(i=0;i<n;i++)
	{
		while(!q.empty()&&q.back()<s[i]&&n-i>k-q.size())
		{
			q.pop_back();
		}
		if(q.size()<k)
			q.push_back(s[i]);
	}
	while(!q.empty())
	{
		if(q.front()<=15&&q.front()>=10)
			printf("%c",q.front()-10+'a');
		else
			printf("%c",q.front()+'0');
		q.pop_front();
	}
}
