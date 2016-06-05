#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int dp[128][128];

int main()
{
	for ( ; ; )
	{
		string inp;
		vector<string> s(1);
		for ( ; (cin >> inp) && (inp != "#"); )
		{
			s.push_back(inp);
		}
		if (cin == false)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		int i;
		for (i = 1; (cin >> inp) && (inp != "#"); ++i)
		{
			for (int j = 1; j < s.size(); ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (inp == s[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		vector<string> ans;
		int px = i - 1;
		int py = s.size() - 1;
		while (px * py > 0)
		{
			if (dp[px][py] == dp[px][py - 1])
			{
				--py;
				continue;
			}
			if (dp[px][py] == dp[px - 1][py])
			{
				--px;
				continue;
			}
			ans.push_back(s[py]);
			--py; --px;
		}
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
