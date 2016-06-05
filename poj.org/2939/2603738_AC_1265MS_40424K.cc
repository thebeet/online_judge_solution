#include <stdio.h>
#include <string.h>

const int p = 10000003;
const int MAXN = 500010;

int hashtable[p];
int endslot;
int slot[MAXN];
int next[MAXN];

void hash_insert(int d)
{
	int m = d % p;
	slot[++endslot] = d;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}

int hash_find(int d)
{
	int m = d % p;
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (slot[pp] == d)
		{	
			return pp;
		}
		pp = next[pp];
	}
	return 0;
}		

int main()
{
	int n, a, b;
	while (scanf("%d", &n), n > 0)
	{
		int ret;
		unsigned int size = n << 2;
		if (size > sizeof(hashtable))
		{
			size = sizeof(hashtable);
		}
		memset(hashtable, 0, size);
		endslot = 0;
		scanf("%d%d", &a, &b);
		long long x = 0;
		long long lla = (long long)a;
		long long llb = (long long)b;
		long long lln = (long long)n;
		while ((ret = hash_find((int)x)) == 0)
		{
			hash_insert((int)x);
			x = ((x * x) % lln * lla + llb) % lln;
		}
		printf("%d\n", n - endslot + ret - 1);
	}
	return 0;
}
