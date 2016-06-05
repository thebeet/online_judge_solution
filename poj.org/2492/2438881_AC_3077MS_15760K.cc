#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAXN 2010

struct path
{
	int f, t;
}paths[2000010];
int s[MAXN];
int p[MAXN];
char color[2010];

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

bool floodfill(int n)
{
	int i;
	for (i = p[n]; i < p[n + 1]; ++i)
	{
		if (color[paths[i].t] == color[n])
		{
			return false;
		}
		if (color[paths[i].t] == 2)
		{
			color[paths[i].t] = color[n] ^ 1;
			if (floodfill(paths[i].t) == false)
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m;
		scanf("%d%d", &n, &m);
		printf("Scenario #%d:\n", ti); 
		
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &paths[i].f, &paths[i].t);
			paths[i + m].f = paths[i].t;
			paths[i + m].t = paths[i].f;
			++s[paths[i].f];
			++s[paths[i].t];
		}
		sort(paths + 1, paths + 1 + m + m, cmp);
		p[1] = 1;
		for (i = 1; i <= n; ++i)
		{
			p[i + 1] = p[i] + s[i];
		}
		
		memset(color, 2, sizeof(color));
		
		for (i = 1; i <= n; ++i)
		{
			if (color[i] == 2)
			{
				color[i] = 0;
				if (floodfill(i) == false)
				{
					break;
				}
			}
		}
		if (i <= n)
		{
			printf("Suspicious bugs found!\n\n");
		}
		else
		{
			printf("No suspicious bugs found!\n\n");
		}				
	}
	return 0;
}
