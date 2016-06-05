#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct tp
{
	int num;
	int id;
}tps[65536];

bool operator < (const tp &t1, const tp &t2)
{
	return (t1.num < t2.num);
}

int dv[65536];
int n, k;

bool check(int ans)
{
	int i;
	int s = 0;
	memset(dv, 0, sizeof(dv));
	for (i = k; i >= 1; --i)
	{
		s += (dv[i] = (tps[i].num / ans));
		if (s >= n)
		{
			break;
		}
	}
	if (s >= n)
	{
		dv[i] -= (s - n);
		return true;
	}
	return false;
}

int main()
{
	int i, j;
	memset(tps, 0, sizeof(tps));
	scanf("%d%d", &n, &k);
	for (i = 1; i <= k; ++i)
	{
		scanf("%d", &tps[i].num);
		tps[i].id = i;
	}
	if (k < n)
	{
		k = n;
	}
	sort(tps + 1, tps + k + 1);
	int lo, hi;
	lo = 1; hi = n + 1;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) >> 1;
		(check(mid) ? lo : hi) = mid;
	}
	check(lo);
	printf("%d\n", lo);
	for (i = 1; i <= k; ++i)
	{
		for (j = 1; j <= dv[i]; ++j)
		{
			printf("%d\n", tps[i].id);
		}
	}
	return 0;
}
