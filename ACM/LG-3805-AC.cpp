#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[11000001];
char str[22000010];
int r[22000010];
int main()
{
	int n,i,id,mx,p,maxn=0;
	scanf("%s",s);
	n=strlen(s);
	str[0]='%';
	p=1;
	str[p++]='#';
	for(i=0;i<n;i++)
	{
		str[p++]=s[i];
		str[p++]='#';
	}
	str[p]='\0';
	r[0]=0;
	n=p;
	id=1;
	mx=1;
	for(i=1;i<n;i++)
	{
		if(i>=mx)
		{
			mx=i;
			while(1)
			{
				mx++;
				if(str[mx]!=str[2*i-mx])
				{
					id=i;
					break;
				}
			}
			r[i]=mx-id;
		}
		else
		{
			r[i]=min(r[2*id-i],mx-i);
			int bnd=r[2*id-i]<(mx-i)?(i+r[2*id-i]):mx;
			while(str[bnd]==str[2*i-bnd])
			{
				bnd++;
			}
			if(bnd>mx)
			{
				id=i;
				mx=bnd;
			}
			r[i]=bnd-i;
		}
		if(r[i]>maxn)
			maxn=r[i];
	}
	printf("%d\n",maxn-1);
	return 0;
}
