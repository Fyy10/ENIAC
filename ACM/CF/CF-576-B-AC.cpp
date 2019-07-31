#include<bits/stdc++.h>
using namespace std;

int main()
{
	double H, L;
	cin >> H >> L;
	printf("%.13lf", 0.5*(L*L - H*H)/H);
	return 0;
}
