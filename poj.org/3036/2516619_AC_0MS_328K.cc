#include <iostream>

using namespace std;

int ans[16][16][16];

void dp_go(int p)
{
	int i, k;
	ans[p][0][0] = 6 * ans[p - 1][1][0];
	for (i = 1; i <= 7; ++i)
	{
		ans[p][i][0] = ans[p - 1][i - 1][0] + 2 * ans[p - 1][i][1] + ans[p - 1][i + 1][0] + 2 * ans[p - 1][i + 1][1];
	}
	ans[p][1][1] = ans[p][1][0];
	
	for (i = 2; i <= 6; i += 2)
	{
		ans[p][i][i / 2] = 2 * ans[p - 1][i - 1][(i / 2) - 1] + 2 * ans[p - 1][i][(i / 2) - 1] + 2 * ans[p - 1][i + 1][(i / 2)];
	}
	
	for (k = 1; k <= 3; ++k)
	{
		for (i = k * 2 + 1; i <= 7; ++i)
		{
			ans[p][i][k] = ans[p - 1][i - 1][k - 1] + ans[p - 1][i - 1][k] + ans[p - 1][i][k - 1] + \
						   ans[p - 1][i][k + 1] + ans[p - 1][i + 1][k] + ans[p - 1][i + 1][k + 1];
		}
		ans[p][k * 2 + 1][k + 1] = ans[p][k * 2 + 1][k];
	}
}

int main()
{
	memset(ans, 0, sizeof(ans));
	ans[0][0][0] = 1;
	for (int i = 1; i <= 14; ++i)
	{
		dp_go(i);
	}
	
	int ti, tn;
	cin >> tn;
	
	for (ti = 1; ti <= tn; ++ti)
	{
		int n;
		cin >> n;
		cout << ans[n][0][0] << endl;
	}
	return 0;
}
