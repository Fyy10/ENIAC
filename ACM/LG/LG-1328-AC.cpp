#include<stdio.h>
int win(int a,int b);
int main()
{
	int ordera[200],orderb[200];
	int i,n,na,nb,pa=0,pb=0,scorea=0,scoreb=0;
	scanf("%d %d %d",&n,&na,&nb);
	for(i=0;i<na;++i)
	{
		scanf("%d",&ordera[i]);
	}
	for(i=0;i<nb;++i)
	{
		scanf("%d",&orderb[i]);
	}
	while(n--)
	{
		if(win(ordera[pa],orderb[pb])==1)
			++scorea;
		else
			if(win(ordera[pa],orderb[pb])==2)
				++scoreb;
		if(pa+1==na)
			pa=0;
		else
			++pa;
		if(pb+1==nb)
			pb=0;
		else
			++pb;
	}
	printf("%d %d\n",scorea,scoreb);
	return 0;
}
int win(int a,int b)	//a towards b 1:win 2:lose 3:equal
{
	int scoretable[5][5]={{3,2,1,1,2},{1,3,2,1,2},{2,1,3,2,1},{2,2,1,3,1},{1,1,2,2,3}};
	return scoretable[a][b];
}
