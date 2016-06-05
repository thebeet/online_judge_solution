#include <stdio.h>
#include <string.h>

const int p = 10000019;
const int MAXN = 100010;
const int cmpsize = 7 * sizeof(int);


int snow[14];
int snow2[7];
int snow3[7];

int hashtable[p];

int endslot = 0;
int slot[MAXN][7];
int next[MAXN];

void hash_insert(int ppp, int *d)
{
	int m = ppp % p;
	++endslot;
	memcpy(slot[endslot], d, cmpsize);
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}		

bool hash_find(int ppp, int *d)
{
	int m = ppp % p;
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (memcmp(slot[pp], d, cmpsize) == 0)
		{	
			return true;
		}
		pp = next[pp];
	}
	return false;
}		

void transfor()
{
	int i;
	memcpy(snow + 7, snow + 1, 24);
	memcpy(snow2 + 1, snow + 1, 24);
	for (i = 2; i <= 6; ++i)
	{
		if (memcmp(snow2 + 1, snow + i, 24) > 0)
		{
			memcpy(snow2 + 1, snow + i, 24);
		}
	}
	for (i = 1; i <= 6; ++i)
	{
		int tmp = snow[i];
		snow[i] = snow[13 - i];
		snow[13 - i] = tmp;
	}
	for (i = 1; i <= 6; ++i)
	{
		if (memcmp(snow2 + 1, snow + i, 24) > 0)
		{
			memcpy(snow2 + 1, snow + i, 24);
		}
	}
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		int minp = 1;
		int sum = 0;
		int xorp = 0;
		for (j = 1; j <= 6; ++j)
		{
			scanf("%d", &snow[j]);
			sum += snow[j];
			xorp ^= snow[j];
			if (snow[j] < snow[minp])
			{
				minp = j;
			}
		}
		//snow2[0] = sum ^ xorp;
		transfor();
		snow2[0] = sum + xorp;
		if (hash_find(snow2[0], snow2))
		{
			printf("Twin snowflakes found.\n");
			return 0;
		}
		else
		{
			hash_insert(snow2[0], snow2);
		}
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}
