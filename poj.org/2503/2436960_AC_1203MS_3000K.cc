#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXN 100

#define lnscanf(ret, fmt, x...) \
{{{ \
	char inp[100]; \
	char *p; \
	memset(inp, 0, sizeof(inp)); \
	p = inp; \
	while (scanf("%c", p), *p != '\n') \
	{ \
		++p; \
	} \
	ret = sscanf(inp, fmt, ##x); \
}}}

struct assigntable
{
	char eng[15];
	char ngeay[15];
}tables[100010];

bool cmp(assigntable w1, assigntable w2)
{
	return (strcmp(w1.ngeay, w2.ngeay) < 0);
} 

int main()
{
	int n, ret;
	char inp[100];
	n = 1;
	while (true)
	{
		lnscanf(ret, "%s%s", tables[n].eng, tables[n].ngeay);
		if (ret == EOF) break;
		++n;
	}
	sort(tables + 1, tables + n, cmp);
	--n;
	
	while (scanf("%s", inp) != EOF)
	{
		int lo, hi, mid;
		lo = 0; hi = n + 1; 
		while (lo + 10 < hi)
		{
			mid = (lo + hi) >> 1;
			ret = strcmp(inp, tables[mid].ngeay);
			if (ret == 0)
			{
				break;
			}
			else if (ret == 1)
			{
				lo = mid;
			}
			else
			{
				hi = mid;
			}
		}
		if (ret != 0)
		{
			for (mid = lo + 1; mid < hi; ++mid)
			{
				if (strcmp(inp, tables[mid].ngeay) == 0)
				{
					break;
				}
			}
			if (mid == hi)
			{
				printf("eh\n");
				continue;
			}
		}
		printf("%s\n", tables[mid].eng);
	}
	return 0;
}
