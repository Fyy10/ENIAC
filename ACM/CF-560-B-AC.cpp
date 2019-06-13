#include<stdio.h>
#include<set>
using namespace std;
multiset<int> a;
multiset<int>::iterator it;
int main()
{
	int n,i,t=0,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		a.insert(tmp);
	}
	i=1;
	it=a.begin();
	while(it!=a.end())
	{
		if(*it>=i)
		{
			t++;
			it++;
			i++;
		}
		else
		{
			it++;
		}
	}
	printf("%d",t);
	return 0;
}
