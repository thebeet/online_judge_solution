#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXN 5010

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

// make end-star graph
struct path
{
	int f, t;
}paths[50010];
int s[MAXN];
int p[MAXN];

int ans[MAXN];

bool cmp(path p1, path p2)
{
	return (p1.t < p2.t);
}

int main()
{
	int i, j, n, m, total;
	total = 0;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	memset(ans, 0, sizeof(ans));
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &paths[i].f, &paths[i].t);
		++s[paths[i].t];
	}
	sort(paths + 1, paths + 1 + m, cmp);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	
	for (i = 1; i <= n; ++i)
	{
		if (s[i] == 0)
		{
			ans[i] = 1;
		}
		else
		{
			for (j = p[i]; j < p[i + 1]; ++j)
			{
				ans[i] += ans[paths[j].f];
				total = MAX(total, ans[paths[j].f]);
			}
		}
	}
	printf("%d\n", total);
	return 0;
}
