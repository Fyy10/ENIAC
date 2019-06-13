#include<iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	if(n%2)
		printf("0");
	else
		cout<<(1<<(n/2));
	return 0;
}
