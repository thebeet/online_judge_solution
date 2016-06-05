#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > graph;

int dp[10010][4];

int tree_dp(const int p, const int mode, const int pre)
{
	if (dp[p][mode] < 0)
	{
		switch (mode)
		{
			case 0:
			{
				dp[p][mode] = 1;
				for (int i = 0; i < graph[p].size(); ++i)
				{
					if (graph[p][i] != pre)
					{
						dp[p][mode] += min(tree_dp(graph[p][i], 1, p), tree_dp(graph[p][i], 0, p));
					}
				}
				break;
			}
			case 1:
			{
				dp[p][mode] = 0;
				for (int i = 0; i < graph[p].size(); ++i)
				{
					if (graph[p][i] != pre)
					{
						dp[p][mode] += tree_dp(graph[p][i], 2, p);
					}
				}
				break;
			}
			case 2:
			{
				if (graph[p].size() == 1)
				{
					dp[p][mode] = graph.size();
				}
				else
				{
					int s(0);
					dp[p][mode] = graph[p].size();
					for (int i = 0; i < graph[p].size(); ++i)
					{
						if (graph[p][i] != pre)
						{
							s += tree_dp(graph[p][i], 2, p);
						}
					}
					for (int i = 0; i < graph[p].size(); ++i)
					{
						if (graph[p][i] != pre)
						{
							dp[p][mode] = min(dp[p][mode], s - tree_dp(graph[p][i], 2, p) + tree_dp(graph[p][i], 0, p));
						}
					}
				}
				break;
			}
		}
		//cerr << "dp[" << p << "][" << mode << "] = " << dp[p][mode] << endl;
	}
	return dp[p][mode];
}

int main()
{
	int n;
	do
	{
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		graph.clear();
		graph.resize(n + 1);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		graph[1].push_back(0);
		cout << min(tree_dp(1, 0, 0), tree_dp(1, 2, 0)) << endl;
		scanf("%d", &n);
	}while (n == 0);
	return 0;
}
