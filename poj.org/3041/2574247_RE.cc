#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 256;

int n;

int map[MAXN][MAXN];

struct path
{
	int f, t;
}paths[10010];
int s[MAXN];
int p[MAXN];

int px[MAXN];
int py[MAXN];
bool gone[MAXN];

int lx[MAXN];
int ly[MAXN];

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

inline int min(int a, int b)
{
	return (a > b) ? a : b;
}


bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

bool hungary_dfs(int pp)
{
	int i;
	if (gone[pp] == false)
	{
		gone[pp] = true;
		for (i = p[pp]; i < p[pp + 1]; ++i)
		{
			if ((py[paths[i].t] == 0) || hungary_dfs(py[paths[i].t])) 
			{
				py[paths[i].t] = pp;
				px[pp] = paths[i].t;
				return true;
			}
		}
	}
	return false;
}

int hungary(void)
{
	int k, i, ans;
	
	memset(px, 0, sizeof(px));
	memset(py, 0, sizeof(py));
	ans = 0;
	
	for (k = 1; k <= n; ++k)
	{
		if (px[k] == 0)
		{
			memset(gone, false, sizeof(gone));
			if (hungary_dfs(k))
			{
				++ans;
			}
		}
	}
	return ans;
}

bool km_dfs(void)
{
	
	return true;
}

/*
int km(void)
{
	int i, j, k;
	
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (i = 1; i <= n; ++i)
	{
		lx = map[i][1];
		for (j = 2; j <= n; ++j)
		{
			lx = max(lx, map[i][j]);
		}
	}
	
	memset(from, 0, sizeof(from));
	memset(out, 0, sizeof(out));
	for (k = 1; k <= n; ++i)
	{
		memset(gone, false, sizeof(gone));
		for (i = 1; i <= n; ++i)
		{
			if (out[i] == 0)
			{
				if (km_dfs())
				{
					break;
				}
			}
		}
		if (i > n)
		{
			break;
		}
	}
	return k - 1;
}
*/
int main()
{
	///* prestar
	int i, m;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &paths[i].f, &paths[i].t);
		++s[paths[i].f];
	}
	sort(paths + 1, paths + 1 + m, cmp);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	printf("%d\n", hungary());
	//*/
	/*
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
		}
	}*/
	return 0;
}
