#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 110
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

struct path
{
	int f, t;
}paths[1010];
int s[MAXN];
int p[MAXN];
int st[MAXN];
int del[MAXN];
bool gone[MAXN];
int gon;

void go(int n)
{
	int i;
	gone[n] = true;
	++gon;
	for (i = p[n]; i < p[n + 1]; ++i)
	{
		if (gone[paths[i].t] == false)
		{
			go(paths[i].t);
		}
	}
}

bool comp(path p1, path p2)
{
	return (p1.f < p2.f);
}

int main()
{
	int ti, n;
	ti = 0;
	while (scanf("%d", &n), n > 0)
	{
		int i, m;
		++ti;
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		
		scanf("%d", &m);
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &paths[i].f, &paths[i].t);
			paths[i + m].f = paths[i].t;
			paths[i + m].t = paths[i].f;
			++s[paths[i].t];
			++s[paths[i].f];
		}
		
		if (m + 1 == n)
		{
			if (n == 1)
			{
				printf("Graph %d is a caterpillar.\n", ti);
				continue;
			}
			sort(paths + 1, paths + 1 + m + m, comp);
			
			p[1] = 1;
			for (i = 2; i <= n; ++i)
			{
				p[i] = p[i - 1] + s[i - 1];
			}
			p[n + 1] = m + m + 1;
			
			memset(gone, false, sizeof(gone));
			
			gon = 0;
			go(1);
			
			if (gon == n)
			{
				memset(del, 0, sizeof(del));
				for (i = 1; i <= n; ++i)
				{
					if (s[i] == 1)
					{
						del[++del[0]] = i;
					}
				}
				if (del[0] == n)
				{
					printf("Graph %d is a caterpillar.\n", ti);
					continue;
				}
				for (i = 1; i <= del[0]; ++i)
				{
					--s[paths[p[del[i]]].t];
				}
				for (i = 1; i <= del[0]; ++i)
				{
					s[del[i]] = 0;
				}
				memset(st, 0, sizeof(st));
				for (i = 1; i <= n; ++i)
				{
					++st[s[i]];
				}
				if ((st[1] == 2) && (st[2] == (n - del[0] - 2)))
				{
					printf("Graph %d is a caterpillar.\n", ti);
					continue;
				}
			}
		}
		printf("Graph %d is not a caterpillar.\n", ti);
	}
	return 0;
}
