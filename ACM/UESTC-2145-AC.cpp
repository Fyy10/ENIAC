#include<stdio.h>
#include<set>
using namespace std;
struct line
{
	int left,right;
};
struct rule
{
	bool operator()(const line u,const line v)
	{
		return u.right<v.left;
	}
};
set<line,rule> s;
set<line,rule>::iterator it;
int main()
{
	int n;
	line tmp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d",&tmp.left,&tmp.right);
		it=s.begin();
		while(s.size()&&it!=s.end())
		{
			if((*it).left<=tmp.right&&(*it).right>=tmp.left)
			{
				tmp.left=min((*it).left,tmp.left);
				tmp.right=max((*it).right,tmp.right);
				s.erase(it);
			}
			it++;
		}
		s.insert(tmp);
		printf("%d ",s.size());
	}
	return 0;
}
