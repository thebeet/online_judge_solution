#include <stdio.h>
#include <algorithm>

using std::max;

const int size = 131072;

int inp[size * 2];
int sum[size];
int inpsize;

int bfind(int key)
{
	int lo = 0;
	int hi = inpsize + 1;
	while (lo + 1 < hi)
	{
		int mid = (lo + hi) >> 1;
		if (sum[mid] < key)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	return lo;
}

int rmq(int f, int t)
{
	int ans = 0;
	f += size;
	t += size;
	while (f <= t)
	{
		ans = max(ans, max(inp[f], inp[t]));
		if (f == t)
		{
			break;
		}
		f = (f + 1) >> 1;
		t = (t - 1) >> 1;
	}
	return ans;
}

int main()
{
	int i, n, m;
	while (scanf("%d", &n), n > 0)
	{
		scanf("%d", &m);
		
		int len = 1;
		int pr, dat;
		inpsize = 0;
		memset(inp, 0, sizeof(inp));
		memset(sum, 0, sizeof(sum));
		
		scanf("%d", &pr);
		for (i = 2; i <= n; ++i)
		{
			scanf("%d", &dat);
			if (dat == pr)
			{
				++len;
			}
			else
			{
				inp[++inpsize + size] = len;
				sum[inpsize] = sum[inpsize - 1] + inp[inpsize + size];
				len = 1;
				pr = dat;
			}
		}
		inp[++inpsize + size] = len;
		sum[inpsize] = sum[inpsize - 1] + inp[inpsize + size];
		
		for (i = size - 1; i >= 1; --i)
		{
			inp[i] = max(inp[i << 1], inp[(i << 1) + 1]);
		}
		
		for (i = 1; i <= m; ++i)
		{
			int x, y;
			int px, py;
			int ans = 1;
			scanf("%d%d", &x, &y);
			px = bfind(x);
			py = bfind(y);
			if (px == py)
			{
				ans = y - x + 1;
			}
			else
			{
				ans = max(ans, sum[px + 1] - x + 1);
				ans = max(ans, y - sum[py]);
				ans = max(ans, rmq(px + 2, py));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
