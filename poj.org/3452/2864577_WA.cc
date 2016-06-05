#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int inp[200010];
int ans[200010];
int outans[200010];
int solt[200010];
bool where[200010];

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		int i, id;
		memset(solt, 0, sizeof(solt));
		int freesolt = 1;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &inp[i]);
			int lo = 0;
			int hi = freesolt;
			while (lo + 1 < hi)
			{
				int mid = (lo + hi) >> 1;
				((solt[mid] > inp[i]) ? lo : hi) = mid;
			}
			ans[i] = hi;
			solt[hi] = inp[i];
			if (hi == freesolt)
			{
				++freesolt;
			}
		}
		if (freesolt - 1 > m)
		{
			cout << "Transportation failed" << endl;
		}
		else
		{
			for (i = 1; i <= n; ++i)
			{
				printf("%d%c", ans[i], ((i == n) ? '\n' : ' '));
				outans[inp[i]] = ans[i]; 
			}
			for (i = 1; i <= n; ++i)
			{
				printf("%d%c", outans[i], ((i == n) ? '\n' : ' '));
			}
		}
	}
	return 0;
}
