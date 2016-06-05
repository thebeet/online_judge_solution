#include <iostream>
#include <algorithm>

using namespace std;

int card[1500010];
int ans[1000010];

int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	for (int i = 1; i <= k; ++i)
	{
		card[i] = i;
	}
	int endp = k;
	int s(0);
	for (int i = 1; i < endp; ++i)
	{
		if ((++s % n) == 0)
		{
			ans[++ans[0]] = card[i];
		}
		for (int j = 0; j < p; ++j)
		{
			card[++endp] = card[++i];
		}
	}
	ans[++ans[0]] = card[endp];
	sort(ans + 1, ans + ans[0] + 1);
	for (int i = 1; i <= ans[0]; ++i)
	{
		cout << ans[i] << endl;
	}
	return 0;
}
