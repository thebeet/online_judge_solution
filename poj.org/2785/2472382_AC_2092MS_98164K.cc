#include <stdio.h>

#define p 23000009
#define MAXN 16000010

int hashtable[p];

int endslot;
int slot[MAXN];
int next[MAXN];

int data[4010][5];

void hash_insert(int d)
{
	int m = d % p;
	if (m < 0) m += p;
	slot[++endslot] = d;
	next[endslot] = hashtable[m];
	hashtable[m] = endslot;
}		

int hash_find(int d)
{
	int m = d % p;
	if (m < 0) m += p;
	int pp = hashtable[m];
	int sum = 0;
	while (pp != 0)
	{
		if (slot[pp] == d)
		{	
			++sum;
		}
		pp = next[pp];
	}
	return sum;
}		

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	ans = 0;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= 4; ++j)
		{
			scanf("%d", &data[i][j]);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			hash_insert(data[i][1] + data[j][2]);
		}
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			ans += hash_find(-data[i][3] - data[j][4]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
