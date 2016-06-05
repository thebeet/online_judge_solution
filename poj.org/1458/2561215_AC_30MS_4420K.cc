#include <iostream>
#include <string>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int dp[1024][1024];

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int i, j;
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= s1.size(); ++i)
		{
			for (j = 1; j <= s2.size(); ++j)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				else
				{
					dp[i][j] = MAX(dp[i][j - 1], dp[i - 1][j]);
				}
			}
		}
		cout << dp[s1.size()][s2.size()] << endl;
	}
	return 0;
}
