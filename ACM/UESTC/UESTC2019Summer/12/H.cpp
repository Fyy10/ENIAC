#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x0, y0, xd, yd;
	char dir;
	scanf("%d %d %c", &x0, &y0, &dir);
	cin >> xd >> yd;
	int ins = 0;
	if (xd > x0 && yd > y0)
	{
		switch (dir)
		{
			case 'O':
			{
				//printf("D\n");
				ins++;
				break;
			}
			case 'S':
			{
				//printf("D\nD\n");
				ins += 2;
				break;
			}
			case 'E':
			{
				//printf("D\nD\nD\n");
				//ins += 3;
				printf("5\n");
				printf("A %d\n", xd - x0);
				printf("D\nD\nD\n");
				printf("A %d\n", yd - y0);
				return 0;
				break;
			}
			default:;
		}
		printf("%d\n", ins+3);
		for (int i = 0; i < ins; i++)
			printf("D\n");
		printf("A %d\nD\nA %d\n", yd - y0, xd - x0);
		return 0;
	}
	if (xd < x0 && yd > y0)
	{
		switch (dir)
		{
			case 'S':
			{
				//printf("D\n");
				ins++;
				break;
			}
			case 'E':
			{
				//printf("D\nD\n");
				ins += 2;
				break;
			}
			case 'N':
			{
				//printf("D\nD\nD\n");
				//ins += 3;
				printf("5\n");
				printf("A %d\n", yd - y0);
				printf("D\nD\nD\n");
				printf("A %d\n", x0 - xd);
				return 0;
				break;
			}
			default:;
		}
		printf("%d\n", ins+3);
		for (int i = 0; i < ins; i++)
			printf("D\n");
		printf("A %d\nD\nA %d\n", x0 - xd, yd - y0);
		return 0;
	}
	if (xd < x0 && yd < y0)
	{
		switch (dir)
		{
			case 'E':
			{
				//printf("D\n");
				ins++;
				break;
			}
			case 'N':
			{
				//printf("D\nD\n");
				ins += 2;
				break;
			}
			case 'O':
			{
				//printf("D\nD\nD\n");
				//ins += 3;
				printf("5\n");
				printf("A %d\n", x0 - xd);
				printf("D\nD\nD\n");
				printf("A %d\n", y0 - yd);
				return 0;
				break;
			}
			default:;
		}
		printf("%d\n", ins+3);
		for (int i = 0; i < ins; i++)
			printf("D\n");
		printf("A %d\nD\nA %d\n", y0 - yd, x0 - xd);
		return 0;
	}
	if (xd > x0 && yd < y0)
	{
		switch (dir)
		{
			case 'N':
			{
				//printf("D\n");
				ins++;
				break;
			}
			case 'O':
			{
				//printf("D\nD\n");
				ins += 2;
				break;
			}
			case 'S':
			{
				//printf("D\nD\nD\n");
				//ins += 3;
				printf("5\n");
				printf("A %d\n", y0 - yd);
				printf("D\nD\nD\n");
				printf("A %d\n", xd - x0);
				return 0;
				break;
			}
			default:;
		}
		printf("%d\n", ins+3);
		for (int i = 0; i < ins; i++)
			printf("D\n");
		printf("A %d\nD\nA %d\n", xd - x0, y0 - yd);
		return 0;
	}
	if (x0 == xd && y0 == yd)
	{
		cout << 0 << endl;
		return 0;
	}
	if (x0 == xd)
	{
		if (yd > y0)
		{
			switch (dir)
			{
				case 'O':
				{
					ins++;
					break;
				}
				case 'S':
				{
					ins += 2;
					break;
				}
				case 'E':
				{
					ins += 3;
					break;
				}
				default:;
			}
			printf("%d\n", ins+1);
			for (int i = 0; i < ins; i++)
				printf("D\n");
			printf("A %d\n", yd - y0);
		}
		else
		{
			switch (dir)
			{
				case 'E':
				{
					ins++;
					break;
				}
				case 'N':
				{
					ins += 2;
					break;
				}
				case 'O':
				{
					ins += 3;
					break;
				}
				default:;
			}
			printf("%d\n", ins+1);
			for (int i = 0; i < ins; i++)
				printf("D\n");
			printf("A %d\n", y0 - yd);
		}
		return 0;
	}
	if (y0 == yd)
	{
		if (xd > x0)
		{
			switch (dir)
			{
				case 'N':
				{
					ins++;
					break;
				}
				case 'O':
				{
					ins += 2;
					break;
				}
				case 'S':
				{
					ins += 3;
					break;
				}
				default:;
			}
			printf("%d\n", ins+1);
			for (int i = 0; i < ins; i++)
				printf("D\n");
			printf("A %d\n", xd - x0);
		}
		else
		{
			switch (dir)
			{
				case 'S':
				{
					ins++;
					break;
				}
				case 'E':
				{
					ins += 2;
					break;
				}
				case 'N':
				{
					ins += 3;
					break;
				}
				default:;
			}
			printf("%d\n", ins+1);
			for (int i = 0; i < ins; i++)
				printf("D\n");
			printf("A %d\n", x0 - xd);
		}
		return 0;
	}
	return 0;
}
