#include <iostream>

using namespace std;

int ans[32][8];

int main()
{
	int i, j;
	ans[0][0] = 1;
	ans[0][3] = 1;
	ans[0][4] = 1;
	for (i = 1; i <= 30; ++i)
	{
		ans[i][0] = ans[i - 1][1] + ans[i - 1][2];
		if (i > 1)
		{
			ans[i][0] += ans[i - 2][0];
		}
		ans[i][1] = ans[i - 1][4];
		ans[i][2] = ans[i - 1][3];
		ans[i][3] = ans[i - 1][2] + ans[i][0];
		ans[i][4] = ans[i - 1][1] + ans[i][0];
	}
	int n;
	while ((cin >> n), n >= 0)
	{
		cout << ans[n][0] << endl;
	}
	return 0;
}
