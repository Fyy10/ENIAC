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
	int n = random(1, 100);
	for(int i = 0; i < n; i++)
	{
		int tmp = random(1, 10000) + 100000;
		printf("%d\n", tmp);
	}
    return 0;
}
