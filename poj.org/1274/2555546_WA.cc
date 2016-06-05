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

bool hungary_dfs(int pp)
{
	int i;
	gone[pp] = true;
	for (i = p[pp]; i < p[pp + 1]; ++i)
	{
		if ((from[paths[i].t] == 0) || ((gone[from[paths[i].t]] == false) && hungary_dfs(from[paths[i].t]))) 
		{
			from[paths[i].t] = pp;
			out[pp] = paths[i].t;
			return true;
		}
	}
	return false;
}

int hungary(void)
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
				if (hungary_dfs(i))
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
	scanf("%d%d", &n, &m);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		int nm;
		scanf("%d", &nm);
		p[i + 1] = p[i] + nm;
		for (int j = p[i]; j < p[i + 1]; ++j)
		{
			paths[j].f = i; 
			scanf("%d", &paths[j].t);
		}
	}
	printf("%d\n", hungary());
	return 0;
}
