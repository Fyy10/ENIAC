#include<stdio.h>
#include<string.h>
int main()
{
	int m,n,i,dict[100],tmp,p=0,checkn=0;
	scanf("%d %d",&m,&n);
	memset(dict,-1,sizeof(dict));
	while(n--)
	{
		scanf("%d",&tmp);
		for(i=0;i<m;++i)
			if(dict[i]==tmp)
				break;
		if(i==m)
		{
			++checkn;
			dict[p]=tmp;
			if(p+1==m)
				p=0;
			else
				++p;
		}
	}
	printf("%d\n",checkn);
	return 0;
}
