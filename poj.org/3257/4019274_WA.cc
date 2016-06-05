#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Component
{
	int w, f, c;
};

vector< Component > Comps[1024];

int dp[1024][1024];

int main()
{
	int len, n, b;
	scanf("%d%d%d", &len, &n, &b);
	for (int i = 0; i < n; ++i)
	{
		int x;
		Component comp;
		scanf("%d%d%d%d", &x, &comp.w, &comp.f, &comp.c);
		Comps[x].push_back(comp);
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			for (int h = 0; h < Comps[i].size(); ++h)
			{
				if ((i + Comps[i][h].w <= len) && (j + Comps[i][h].c <= b))
				{
					dp[i + Comps[i][h].w][j + Comps[i][h].c] = max(dp[i + Comps[i][h].w][j + Comps[i][h].c], dp[i][j] + Comps[i][h].f);
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < b; ++j)
	{
		if (dp[len][j] > 0)
		{
			ans = max(ans, dp[len][j]);
		}
	}
	if (ans == 0)
	{
		ans = -1;
	}
	cout << ans << endl;
	return 0;
}

