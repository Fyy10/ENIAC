#include<bits/stdc++.h>
using namespace std;

int main()
{
	double x, y;
	cin >> x >> y;
	double xy = y * log(x);
	double yx = x * log(y);
	if (fabs(xy - yx) < 1e-5)
		cout << "=\n";
	else
	{
		if (xy > yx)
			cout << ">\n";
		else
			cout << "<\n";
	}
	return 0;
}
