#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

struct path
{
	int f, t;
}paths[10010];
bool gone[1010];
int dl[1010];
int dend;
bool ans[1010];
int cow[110];
path *p_paths[1010];
int s_paths[1010];

bool comp(path p1, path p2)
{
	return (p1.f < p2.f);
}

int main()
{
	int i, n, k, m, tar, j, ansn;
	
	scanf("%d%d%d", &k, &n, &m);
	for (i = 1; i <= k; ++i)
	{
		scanf("%d", &cow[i]);
	}
	
	memset(ans, true, sizeof(ans));
	memset(p_paths, 0, sizeof(p_paths));
	memset(s_paths, 0, sizeof(s_paths));
	
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &paths[i].f, &paths[i].t);
		++s_paths[paths[i].f];
	}
	sort(paths + 1, paths + 1 + m, comp);
	p_paths[paths[1].f] = &paths[1];
	for (i = 2; i <= m; ++i)
	{
		if (paths[i].f != paths[i - 1].f)
		{
			p_paths[paths[i].f] = &paths[i];
		}
	}
	
	for (i = 1; i <= k; ++i)
	{
		memset(gone, false, sizeof(gone));
		gone[cow[i]] = true;
		dl[0] = 0;
		dl[1] = cow[i];
		dend = 1;
		while (dl[0] < dend)
		{
			path *p;
			tar = dl[++dl[0]];
			p = p_paths[tar];
			for (j = 1; j <= s_paths[tar]; ++j)
			{
				if (gone[p->t] == false)
				{
					gone[p->t] = true;
					dl[++dend] = p->t;
				}
				++p;
			}
		}
		for (j = 1; j <= n; ++j)
		{
			ans[j] &= gone[j];
		}
	}
	
	ansn = 0;
	for (j = 1; j <= n; ++j)
	{
		if (ans[j])
		{
			++ansn;
		}
	}
	printf("%d\n", ansn);
	return 0;
}
