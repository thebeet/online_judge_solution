#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int inp[200010];
int ans[200010];
int solt[200010];

typedef pair<int, int> fmtans;

fmtans out[200010];

bool operator < (const fmtans &f1, const fmtans &f2)
{
	return (f1.first < f2.first);
}

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		int i;
		memset(solt, 0, sizeof(solt));
		memset(ans, 0, sizeof(ans));
		memset(out, 0, sizeof(out));
	
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
				out[i].first = inp[i];
				out[i].second = ans[i];
			}
			sort(out + 1, out + 1 + n);
			for (i = 1; i <= n; ++i)
			{
				printf("%d%c", out[i].second, ((i == n) ? '\n' : ' '));
			}
		}
	}
	return 0;
}
