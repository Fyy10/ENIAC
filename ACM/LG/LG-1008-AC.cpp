#include<bits/stdc++.h>
using namespace std;

bool judge(int a)
{
	if(a/1000||2*a/1000||3*a/1000)
		return 0;
	int num[10];
	memset(num,0,sizeof(num));
	num[a/100]++;
	num[a%100/10]++;
	num[a%10]++;
	num[2*a/100]++;
	num[2*a%100/10]++;
	num[2*a%10]++;
	num[3*a/100]++;
	num[3*a%100/10]++;
	num[3*a%10]++;
	for(int i=1;i<=9;i++)
	{
		if(num[i]>1 || num[i]==0)
			return 0;
	}
	return 1;
}

int main()
{
	int i;
	for(i=123;i<=333;i++)
	{
		if(judge(i))
			cout << i << ' ' << 2*i << ' ' << 3*i << endl;
	}
	return 0;
}
