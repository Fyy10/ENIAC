#include<bits/stdc++.h>
using namespace std;

struct node
{
	int left;
	int right;
	int maxv;
	int minv;
}tree[50000];

int a[10002];

void build(int x, int left, int right)
{
	tree[x].left = left;
	tree[x].right = right;
	if (left == right)
	{
		tree[x].minv = a[left];
		tree[x].maxv = a[right];
		return;
	}
	int mid = (left + right) >> 1;
	build(x<<1, left, mid);
	build(x<<1|1, mid+1, right);
	tree[x].maxv = max(tree[x<<1].maxv, tree[x<<1|1].maxv);
	tree[x].minv = min(tree[x<<1].minv, tree[x<<1|1].minv);
}

int findmax(int x, int left, int right)
{
	if (tree[x].left == left && tree[x].right == right)
		return tree[x].maxv;
	int mid = (tree[x].left + tree[x].right) >> 1;
	if (right <= mid)
		return findmax(x<<1, left, right);
	if (left > mid)
		return findmax(x<<1|1, left, right);
	int ml = findmax(x<<1, left, mid), mr = findmax(x<<1|1, mid+1, right);
	return max(ml, mr);
}

int findmin(int x, int left, int right)
{
	if (tree[x].left == left && tree[x].right == right)
		return tree[x].minv;
	int mid = (tree[x].left + tree[x].right) >> 1;
	if (right <= mid)
		return findmin(x<<1, left, right);
	if (left > mid)
		return findmin(x<<1|1, left, right);
	int ml = findmin(x<<1, left, mid), mr = findmin(x<<1|1, mid+1, right);
	return min(ml, mr);
}

int main()
{
	int m, n, t, x1, y1, x2, y2;
	cin >> t;
	while (t--)
	{
		cin >> n;
		a[1] = 0;
		for (int i = 2; i <= n+1; i++)
		{
			scanf("%d", &a[i]);
			a[i] += a[i-1];
		}
		cin >> m;
		build(1, 1, 1+n);
		while (m--)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (y1 < x2) printf("%d\n", findmax(1, x2+1, y2+1) - findmin(1, x1, y1));
			else
			{
				int fmax = -100000;
				for (int j = x2; j <= y1; j++)
				{
					int tmp = findmax(1, j+1, y2+1) - findmin(1, x1, j);
					if (tmp > fmax)
						fmax = tmp;
				}
				printf("%d\n", fmax);
			}
		}
	}
	return 0;
}
