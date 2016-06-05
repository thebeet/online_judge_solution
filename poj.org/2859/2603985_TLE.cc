#include <stdio.h>
#include <string.h>

const int p = 10000007;
const int MAXN = 500010;

int hashtable[p];

int endslot = 0;
int slotx[MAXN];
int sloty[MAXN];
int next[MAXN];

void hash_insert(int x, int y)
{
	int m = ((x + y) ^ (x - y) ^ (x >> 4)) % p;
	if (m < 0)
	{
		m += p;
	}
	slotx[++endslot] = x;
	sloty[endslot] = y;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}

bool hash_find(int x, int y)
{
	int m = ((x + y) ^ (x - y) ^ (x >> 4)) % p;
	if (m < 0)
	{
		m += p;
	}
	int pp = hashtable[m];
	while (pp != 0)
	{
		if ((slotx[pp] == x) && (sloty[pp] == y))
		{	
			return true;
		}
		pp = next[pp];
	}
	return false;
}		

int main()
{
	int i, n, x, y, w, h;
	scanf("%d", &n);
	scanf("%d%d", &w, &h);
	memset(hashtable, 0, sizeof(hashtable));
	memset(slotx, 0, sizeof(slotx));
	memset(sloty, 0, sizeof(sloty));
	memset(next, 0, sizeof(next));
	for (i = 1; i <= n; ++i)
	{
		scanf("%d%d", &x, &y);
		hash_insert(x, y);
	}
	int ans = 0;
	for (i = 1; i <= n; ++i)
	{
		if (hash_find(slotx[i] + w, sloty[i]) && hash_find(slotx[i], sloty[i] + h) && hash_find(slotx[i] + w, sloty[i] + h))
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
