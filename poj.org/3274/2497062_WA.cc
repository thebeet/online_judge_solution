#include <stdio.h>
#include <string.h>

#define MAXN 100010
#define p 10000019

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int hashtable[p];

int k, sizek;

int endslot;
int slot[MAXN][30];
int data[MAXN];
int next[MAXN];

int sump[30];

void hash_insert(int pp, int d, int *newdata)
{
	int m = pp % p;
	data[++endslot] = d;
	memcpy(slot[endslot], newdata, sizek);
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}		

int hash_find(int ppp, int *d)
{
	int m = ppp % p;
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (memcmp(slot[pp], d, sizek) == 0)
		{
			return data[pp];
		}
		pp = next[pp];
	}
	return MAXN;
}		

int main()
{
	int i, j, n, m, pr, ans, mn, sum;
	
	scanf("%d%d", &n, &k);
	sizek = k * sizeof(int);
	memset(sump, 0, sizeof(sump));
	hash_insert(0, 0, sump);
	pr = 0;
	ans = 0;
	
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &m);

		pr ^= m;
		mn = 1;
		sum = 0;
		for (j = 0; j < k; ++j)
		{
			sump[j] += (m & 1);
			m >>= 1;
			mn = MIN(sump[j], mn);
			sum += sump[j];
		} 
		if (mn > 0)
		{
			for (j = 0; j < k; ++j)
			{
				--sump[j];
			}
			sum -= k;
		}
		
		int ret1 = hash_find(pr + sum, sump);
		if (ret1 < MAXN)
		{
			ans = MAX(ans, i - ret1);
		}
		else
		{
			hash_insert(pr + sum, i, sump);
		}
	}
	printf("%d\n", ans);
	return 0;
}
