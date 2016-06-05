#include <iostream>
#include <algorithm>

using namespace std;

int cow[10010];
int s[2][10010];

int main()
{
	int i, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &cow[i]);
		if (cow[i] == 1)
		{
			s[0][i] = s[0][i - 1] + 1;
			s[1][i] = s[1][i - 1];
		}
		else
		{
			s[0][i] = s[0][i - 1];
			s[1][i] = s[1][i - 1] + 1;
		}
	}
	int ans = n;
	for (int i = 0; i <= n; ++i)
	{
		ans = min(ans, s[1][i] + s[0][n] - s[0][i]);
	}
	cout << ans << endl;
	return 0;
}
