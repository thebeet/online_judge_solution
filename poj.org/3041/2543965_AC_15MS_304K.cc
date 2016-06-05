#include <stdio.h>
#include <algorithm>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

const int MAXN = 1024;

int n;

struct path
{
	int f, t;
}paths[10010];
int s[MAXN];
int p[MAXN];

int from[MAXN];
int out[MAXN];
bool gone[MAXN];

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

bool dfs(int pp)
{
	int i;
	gone[pp] = true;
	for (i = p[pp]; i < p[pp + 1]; ++i)
	{
		if ((from[paths[i].t] == 0) || ((gone[from[paths[i].t]] == false) && dfs(from[paths[i].t]))) 
		{
			from[paths[i].t] = pp;
			out[pp] = paths[i].t;
			return true;
		}
	}
	return false;
}

int binary_match(void)
{
	int k, i;
	memset(from, 0, sizeof(from));
	memset(out, 0, sizeof(out));
	
	for (k = 1; k <= n; ++k)
	{
		memset(gone, false, sizeof(gone));
		for (i = 1; i <= n; ++i)
		{
			if (out[i] == 0)
			{
				if (dfs(i))
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

int main()
{
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
	printf("%d\n", binary_match());
	return 0;
}
