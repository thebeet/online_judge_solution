#include <stdio.h>
#include <string.h>

const int p = 10000019;
const int MAXN = 100010;

int snow[7];
int snow2[7];

int hashtable[p];

int endslot = 0;
int slot[MAXN][7];
int next[MAXN];

void hash_insert(int ppp, int *d)
{
	int m = ppp % p;
	++endslot;
	memcpy(slot[endslot], d, 28);
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}		

bool hash_find(int ppp, int *d)
{
	int m = ppp % p;
	int pp = hashtable[m];
	while (pp != 0)
	{
		if (memcmp(slot[pp], d, 28) == 0)
		{	
			return true;
		}
		pp = next[pp];
	}
	return false;
}		


void transfor(int *snow, int minp, int p)
{
	int i;
	int minp1, minp2, minp_1, minp_2;
	
	switch (minp)
	{
	case 1:
		minp_1 = 6;
		minp_2 = 5;
		minp1 = 2;
		minp2 = 3;
		break;
	case 2:
		minp_1 = 1;
		minp_2 = 6;
		minp1 = 3;
		minp2 = 4;
		break;
	case 3:
		minp_1 = 2;
		minp_2 = 1;
		minp1 = 4;
		minp2 = 5;
		break;
	case 4:
		minp_1 = 3;
		minp_2 = 2;
		minp1 = 5;
		minp2 = 6;
		break;
	case 5:
		minp_1 = 4;
		minp_2 = 3;
		minp1 = 6;
		minp2 = 1;
		break;
	case 6:
		minp_1 = 5;
		minp_2 = 4;
		minp1 = 1;
		minp2 = 2;
		break;
	}
	
	if ((snow[minp1] < snow[minp_1]) || ((snow[minp1] == snow[minp_1]) && (snow[minp2] < snow[minp_2])))
	{
		for (i = 1; i <= 6; ++i)
		{
			snow2[i] = snow[minp];
			minp = minp % 6 + 1;
		}
	}
	else
	{
		for (i = 1; i <= 6; ++i)
		{
			snow2[i] = snow[minp];
			minp = (minp + 4) % 6 + 1;
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
			sum += snow[j] * j * j;
			xorp ^= snow[j];
			if (snow[j] < snow[minp])
			{
				minp = j;
			}
		}
		transfor(snow, minp, i);
		snow2[0] = sum ^ xorp;
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
