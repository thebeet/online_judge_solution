#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define p 10000019


#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int hashtable[p];

int endslot;
int slot[MAXN];
int data[MAXN];
int next[MAXN];

void hash_insert(int d, int newdata)
{
	int m = d % p;
	slot[++endslot] = d;
	data[endslot] = newdata;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}		

int hash_find(int d)
{
	int m = d % p;
	int pp = hashtable[m];
	int minp = 1000000;
	while (pp != 0)
	{
		if (slot[pp] == d)
		{	
			minp = MIN(minp, data[pp]);
		}
		pp = next[pp];
	}
	return minp;
}		

int main()
{
	int i, n, k, m, pr, tar, ans;
	scanf("%d%d", &n, &k);
	tar = (1 << k) - 1;
	hash_insert(0, 0);
	pr = 0;
	ans = 0;
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);
		pr ^= m;
		hash_insert(pr, i);
		int ret1 = hash_find(pr);
		int ret2 = hash_find(pr ^ tar);
		ret1 = MIN(ret1, ret2);
		ans = MAX(ans, i - ret1);
	}
	printf("%d\n", ans);
	return 0;
}
