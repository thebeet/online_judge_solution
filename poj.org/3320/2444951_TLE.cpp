#include <stdio.h>
#include <string.h>

#define p 11850427
#define MAXN 1000010
int hash[11900000];
int table[MAXN];
int pos[MAXN];
int next[MAXN];
bool nneed[MAXN];

int find(int t, int po)
{
	int m;
	m = t % p;
	if (hash[m] == 0)
	{
		hash[m] = ++table[0];
	}
	else
	{
		int nx = hash[m];
		do
		{
			if (table[nx] == t)
			{
				return nx;
			}
			nx = next[nx];
		}
		while (next[nx] == 0);
		next[nx] = ++table[0];
	}
	table[table[0]] = t;
	pos[table[0]] = po;
	next[table[0]] = 0;
	return 0;
}		

int main()
{
	int i, n, m, lo, ans, ret;
	scanf("%d", &n);
	memset(nneed, false, sizeof(nneed));
	lo = 1;
	ans = n;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		if ((ret = find(m, i)) == 0)
		{
			ans = i - lo + 1;
		}
		else
		{
			nneed[pos[ret]] = true;
			pos[ret] = i;
			while (nneed[lo])
			{
				++lo;
			}
			if ((i - lo + 1) < ans) ans = i - lo + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
