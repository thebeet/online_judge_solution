#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// make pre-star graph
struct path
{
	int f, t;
}paths[2048];
bool bridge[MAXN][MAXN];

int s[MAXN];
int p[MAXN];
int ancestor[MAXN];
int deep[MAXN];
bool cut[MAXN];
char gone[MAXN];
int color[MAXN];
int deg[MAXN];
int root;

void dfs(int pp, int father, int d)
{
	gone[pp] = 1;
	deep[pp] = d;
	ancestor[pp] = d;
	
	int tot = 0;
	
	for (int i = p[pp]; i < p[pp + 1]; ++i)
	{
		if ((paths[i].t != father) && (gone[paths[i].t] == 1))
		{
			ancestor[pp] = MIN(ancestor[pp], deep[paths[i].t]);
		}
		if (gone[paths[i].t] == 0)
		{
			dfs(paths[i].t, pp, d + 1);
			++tot;
			ancestor[pp] = MIN(ancestor[pp], ancestor[paths[i].t]);
			if (((pp == root) && (tot > 1)) || ((pp != root) && (ancestor[paths[i].t] >= deep[pp])))
			{
				cut[pp] = true;
			}
			if (ancestor[paths[i].t] > deep[pp])
			{
				bridge[pp][paths[i].t] = true;
				bridge[paths[i].t][pp] = true;
				//printf("bridge %d %d\n", pp, paths[i].t);
			}
		}
	}
	gone[pp] = 2;
}

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

void dfs2(int pp, int c)
{
	int i;
	color[pp] = c;
	for (i = p[pp]; i < p[pp + 1]; ++i)
	{
		if ((color[paths[i].t] == 0) && (bridge[pp][paths[i].t] == false))
		{
			dfs2(paths[i].t, c);
		}
	}
}

int main()
{
	int i, n, m;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	scanf("%d%d", &n, &m);
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
	
	root = 1;
	memset(gone, 0, sizeof(gone));
	memset(cut, false, sizeof(cut));
	memset(bridge, false, sizeof(cut));
	memset(deep, 0, sizeof(deep));
	dfs(1, 0, 0);
	
	int k = 0;
	memset(color, 0, sizeof(color));
	for (i = 1; i <= n; ++i)
	{
		if (color[i] == 0)
		{
			++k;
			dfs2(i, k);
		}
	}
	
	if (k == 1)
	{
		printf("0\n");
	}
	else
	{
		for (i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (bridge[i][j])
				{
					++deg[color[i]];
					++deg[color[j]];
				}
			}
		}
		int ans = 0;
		for (i = 1; i <= k; ++i)
		{
			if (deg[i] == 1)
			{
				++ans;
			}
		}
		printf("%d\n", (ans + 1) / 2);
	}
	return 0;
}
