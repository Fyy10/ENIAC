#include<bits/stdc++.h>
#define random(a, b) ((a) + rand()%((b) - (a) + 1))
using namespace std;

stringstream ss;

int main(int argc, char *argv[])
{
    int seed = time(NULL);
    if(argc > 1)
    {
        ss.clear();
        ss << argv[1];
        ss >> seed;
    }
    srand(seed);
	int x0 = random(0, 10), y0 = random(0, 10), xd = random(0, 10), yd = random(0, 10), state = random(1, 4);
	cout << x0 << " " << y0 << " ";
	switch (state)
	{
		case 1:
		{
			cout << "E\n";
			break;
		}
		case 2:
		{
			cout << "O\n";
			break;
		}
		case 3:
		{
			cout << "N\n";
			break;
		}
		case 4:
		{
			cout << "S\n";
			break;
		}
		default:;
	}
	cout << xd << " " << yd << endl;
    return 0;
}
