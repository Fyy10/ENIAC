#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[100000];
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int tmp = a[0];
	for (int i = 1; i < n; i++)
		tmp ^= a[i];
	if (!tmp)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
