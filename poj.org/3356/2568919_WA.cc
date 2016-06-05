#include <iostream>
#include <string>

using namespace std;

string inp1, inp2;
int n1, n2;
int dp[2][4010];

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}
inline int min(int a, int b)
{
	return (a < b) ? a : b;
}

int main()
{
	cin >> n1 >> inp1 >> n2 >> inp2;
	int i, j;
	int p1 = 0;
	int p2 = 1;
	for (i = 0; i <= n2; ++i)
	{
		dp[0][i] = i;
	}
	for (i = 0; i < n1; ++i)
	{
		dp[p1][0] = i;
		for (j = 0; j < n2; ++j)
		{
			if (inp1[i] == inp2[j])
			{
				dp[p2][j + 1] = dp[p1][j];
			}
			else
			{
				dp[p2][j + 1] = min(min(dp[p2][j], dp[p1][j + 1]), dp[p1][j]) + 1;
			}
		}
		p2 ^= 1;
		p1 ^= 1;
	}
	cout << dp[p1][n2] << endl;
	return 0;
}
