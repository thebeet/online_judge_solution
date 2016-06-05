#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 210
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int gold[MAXN];
int stor[MAXN];

struct path
{
	int f, t;
	int q;
}paths[20010];
int s[MAXN];
int p[MAXN];
int color[MAXN];
int t_gold;
int t_stor;

bool comp(path p1, path p2)
{
	return (p1.f < p2.f);
}

void floodfill(int pp, int c, int q)
{
	int i;
	color[pp] = c;
	t_gold += gold[pp];
	t_stor += stor[pp];
	for (i = p[pp]; i < p[pp + 1]; ++i)
	{
		if ((color[paths[i].t] == 0) && (paths[i].q <= q))
		{
			floodfill(paths[i].t, c, q);
		}
	}
}

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i, m;
		int lo, hi, mid;
		int s_gold, s_stor;
		memset(gold, 0, sizeof(gold));
		memset(stor, 0, sizeof(stor));
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		
		lo = 100000000;
		hi = 0;
		s_gold = 0;
		s_stor = 0;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &gold[i]);
		}
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &stor[i]);
			if (gold[i] > 0)
			{
				if (stor[i] > gold[i])
				{
					stor[i] -= gold[i];
					gold[i] = 0;
				} 
				else
				{
					gold[i] -= stor[i];
					stor[i] = 0;
				}
			}
			s_gold += gold[i];
			s_stor += stor[i];
		}
		scanf("%d", &m);
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &paths[i].f, &paths[i].t, &paths[i].q);
			++s[paths[i].f];
			++s[paths[i].t];
			paths[i + m].f = paths[i].t;
			paths[i + m].t = paths[i].f;
			paths[i + m].q = paths[i].q;
			lo = MIN(paths[i].q, lo);
			hi = MAX(paths[i].q, hi);
		}
		--lo;
		
		if (s_gold == 0)
		{
			printf("%d\n", 0);
			continue;
		}
		if (s_stor < s_gold)
		{
			printf("No Solution\n");
			continue;
		}
		
		sort(paths + 1, paths + 1 + m + m, comp);
		p[1] = 1;
		for (i = 2; i <= n; ++i)
		{
			p[i] = p[i - 1] + s[i - 1];
		}
		p[n + 1] = m + m + 1;
		
		mid = hi;
		memset(color, 0, sizeof(color));
		
		for (i = 1; i <= n; ++i)
		{
			if (color[i] == 0)
			{
				t_gold = 0;
				t_stor = 0;
				floodfill(i, ++color[0], mid);
				if (t_gold > t_stor)
				{
					break;
				}
			}
		}
		if (i <= n)
		{
			printf("No Solution\n");
			continue;
		}

		while (lo + 1 < hi)
		{
			mid = (lo + hi) >> 1;
			memset(color, 0, sizeof(color));
			
			for (i = 1; i <= n; ++i)
			{
				if (color[i] == 0)
				{
					t_gold = 0;
					t_stor = 0;
					floodfill(i, ++color[0], mid);
					if (t_gold > t_stor)
					{
						break;
					}
				}
			}
			
			if (i > n)
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		printf("%d\n", hi);
	}
	return 0;
}
		
				
	
