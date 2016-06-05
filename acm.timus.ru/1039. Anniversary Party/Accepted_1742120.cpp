#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 6010;

// make pre-star graph
struct path
{
	int f, t;
}paths[100010];
int s[MAXN];
int p[MAXN];
int father[MAXN];
int weight[MAXN];
int dp[MAXN][2];
bool calced[MAXN];

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

void calc(int pp)
{
	if (calced[pp] == false)
	{
		int sumuse = weight[pp];
		int sumunuse = 0;
		for (int i = p[pp]; i < p[pp + 1]; ++i)
		{
			calc(paths[i].t);
			sumuse += dp[paths[i].t][0];
			sumunuse += max(dp[paths[i].t][1], dp[paths[i].t][0]);
		}
		dp[pp][0] = sumunuse;
		dp[pp][1] = sumuse;
	}
}

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

int main()
{
	int i, n, m;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	memset(weight, 0, sizeof(weight));
	memset(dp, 0, sizeof(dp));
	memset(calced, 0, sizeof(calced));
	
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &weight[i]);
	}
	m = n - 1;
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d", &paths[i].t, &paths[i].f);
		++s[paths[i].f];
		father[paths[i].t] = paths[i].f;
	}
	sort(paths + 1, paths + 1 + m, cmp);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	
	int root = 1;
	while (father[root] > 0)
	{
		root = father[root];
	}
	
	calc(root);
	
	printf("%d\n", max(dp[root][1], dp[root][0]));
	return 0;
}
