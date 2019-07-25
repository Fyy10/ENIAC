#include<bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;
	int tmp;
	while (!s.empty())
		s.pop();
	while (scanf("%d", &tmp) == 1)
	{
		if (tmp == 0)
			break;
		s.push(tmp);
	}
	while (!s.empty())
	{
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}
