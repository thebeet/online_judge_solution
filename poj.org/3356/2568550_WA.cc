#include <iostream>
#include <string>

using namespace std;

string inp1, inp2;
int n1, n2;
int dp[4010][4010];

inline int max(int a, int b)
{
	return (a > b) ? a : b;
}

int main()
{
	cin >> n1 >> inp1 >> n2 >> inp2;
	int i, j;
	for (i = 0; i < n1; ++i)
	{
		for (j = 0; j < n2; ++j)
		{
			if (inp1[i] == inp2[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
			{
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	cout << n2 - dp[n1][n2] << endl;
	return 0;
}
