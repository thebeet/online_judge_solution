#include <cstdio>
#include <algorithm>

using namespace std;

int map[32][32];

int father[32];

int find(int p)
{
	if (father[p] != p)
	{
		father[p] = find(father[p]);
	}
	return father[p];
}

struct path
{
	int f, t, q;
}paths[5010];

bool cmp(const path &p1, const path &p2)
{
	if (p1.q == p2.q)
	{
		if (p1.f == p2.f)
		{
			return (p1.t < p2.t);
		}
		return (p1.f < p2.f);
	}
	return (p1.q < p2.q);
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, n, k;
		k = 0;
		scanf("%d", &n);
		
		for (i = 1; i <= n; ++i)
		{
			father[i] = i;
		}
		
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				if (j != 1)
				{
					scanf(",");
				}
				scanf("%d", &map[i][j]);
				if ((i < j) && (map[i][j] > 0))
				{
					paths[++k].f = i;
					paths[k].t = j;
					paths[k].q = map[i][j];
				}
			}
		}
		sort(paths + 1, paths + 1 + k, cmp);
		printf("Case %d:\n", ti);
		for (i = 1; i <= k; ++i)
		{
			int f1 = find(paths[i].f);
			int f2 = find(paths[i].t);
			if (f1 != f2)
			{
				printf("%c-%c %d\n", paths[i].f + 'A' - 1, paths[i].t + 'A' - 1, paths[i].q);
				father[f1] = f2;
			}
		}
	}
	return 0;
}
