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
	memset(dp, -1, sizeof(dp));
	for (int j = 0; j < b; ++j)
	{
		dp[0][j] = 0;
	}
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			if (dp[i][j] >= 0)
			{
				for (unsigned int h = 0; h < Comps[i].size(); ++h)
				{
					int nextw = i + Comps[i][h].w;
					int nextc = j + Comps[i][h].c;
					if (j + Comps[i][h].c <= b)
					{
						dp[nextw][nextc] = max(dp[nextw][nextc], dp[i][j] + Comps[i][h].f);
					}
				}
			}
		}
	}
	cout << dp[len][b] << endl;
	return 0;
}

