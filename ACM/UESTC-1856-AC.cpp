#include<stdio.h>
#include<string.h>
int satisfy(int *a,int n);
int main()
{
	char s[100001];
	int p1,p2,i,a[26],found=0,total=0;
	memset(a,0,sizeof(a));
	scanf("%s",s);
	for(i=0;i<26;++i)
	{
		scanf("%d",&a[i]);
		total+=a[i];
	}
	p1=0;
	p2=p1+total;
	for(i=p1;i<p2;++i)
	{
		--a[s[i]-'a'];
	}
	if(satisfy(a,26))
		found=1;
	while(p2<strlen(s))
	{
		++a[s[p1]-'a'];
		++p1;
		--a[s[p2]-'a'];
		p2=p1+total;
		if(satisfy(a,26))
		{
			found=1;
			break;
		}
	}
	if(found)
		printf("Yes");
	else
		printf("No");
	return 0;
}
int satisfy(int *a,int n)
{
	int i,ans=1;
	for(i=0;i<n;++i)
	{
		if(a[i])
		{
			ans=0;
			break;
		}
	}
	return ans;
}
