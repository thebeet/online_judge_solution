#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct assigntable
{
	char str[20];
	int val;
}tables[1100];

char inp[300];
int n;

bool cmp(assigntable w1, assigntable w2)
{
	return (strcmp(w1.str , w2.str) < 0);
}

int calcvalue(char *inp)
{
	int lo, hi, mid, ret;
	lo = 0; hi = n + 1;
	while (lo + 4 < hi)
	{
		mid = (lo + hi) >> 1;
		ret = strcmp(inp, tables[mid].str);
		if (ret == 0)
		{
			return tables[mid].val;
		}
		if (ret == 1)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	for (mid = lo + 1; mid < hi; ++mid)
	{
		if (strcmp(inp, tables[mid].str) == 0)
		{
			return tables[mid].val;
		}
	}
	return 0;
}	

int main()
{
	int i, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%s%d", tables[i].str, &tables[i].val);
	}
	sort(tables + 1, tables + 1 + n, cmp);
	
	for (i = 1; i <= m; ++i)
	{
		int s;
		s = 0;
		while (scanf("%s", inp), inp[0] != '.')
		{
			s += calcvalue(inp);
		}
		printf("%d\n", s);
	}
	return 0;
}
