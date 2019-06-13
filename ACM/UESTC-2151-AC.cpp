#include<stdio.h>
#include<set>
using namespace std;
struct team
{
	int ac;
	int pe;
};
struct rule
{
	bool operator()(const team u,const team v)
	{
		return u.ac==v.ac?u.pe>v.pe:u.ac<v.ac;
	}
};
multiset<team,rule> teams;
multiset<team,rule>::iterator it;
int tac[100001]={0};
int tpe[100001]={0};
int main()
{
	int n,m,t,p;
	team tmp;
	scanf("%d %d",&n,&m);
	while(m--)
	{
		scanf("%d %d",&t,&p);
		tmp.ac=tac[t];
		tmp.pe=tpe[t];
		tac[t]++;
		tpe[t]+=p;
		if(t==1)
		{
			it=teams.begin();
			while(teams.size()&&((tac[1]>(*it).ac)||(tac[1]==(*it).ac&&tpe[1]<=(*it).pe)))
			{
				teams.erase(it);
				it++;
			}
		}
		else
		{
			if(tmp.ac>tac[1]||(tmp.ac==tac[1]&&tmp.pe<tpe[1]))
			{
				teams.erase(teams.find(tmp));
			}
			tmp.ac++;
			tmp.pe+=p;
			if(tmp.ac>tac[1]||(tmp.ac==tac[1]&&tmp.pe<tpe[1]))
			{
				teams.insert(tmp);
			}
		}
		printf("%d\n",teams.size()+1);
	}
	return 0;
}
