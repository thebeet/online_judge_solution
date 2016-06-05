#include <iostream>
#include <algorithm>

using namespace std;

struct block
{
	int h, a, c;
};

bool operator < (const block &b1, const block &b2)
{
	return b1.a < b2.a;
}

block blocks[512];

bool dp[2][65536];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d%d", &blocks[i].h, &blocks[i].a, &blocks[i].c);
	}
	sort(blocks + 0, blocks + n);
	int p0(0), p1(1);
	memset(dp, false, sizeof(dp));
	dp[p0][0] = true;
	for (int i = 0; i < n; ++i)
	{
		memcpy(dp[p1], dp[p0], sizeof(dp[p0]));
		for (int j = 0; j < blocks[i].a; ++j)
		{
			if (dp[p0][j])
			{
				for (int k(0), newh(j + blocks[i].h); (k < blocks[i].c) & (newh <= blocks[i].a); ++k, newh += blocks[i].h)
				{
					dp[p1][newh] = true;
				}
			}
		}
		swap(p0, p1);
	}
	int ans = blocks[n - 1].a;
	while (dp[p0][ans] == false)
	{
		--ans;
	}
	cout << ans << endl;
	return 0;
}

