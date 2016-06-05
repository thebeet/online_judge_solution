#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int schedule[64][8];

int ans[8][8];

int bans[8][8];
int nans;
int sans;

int useq[128];

int findmost()
{
	int i, p;
	p = 0;
	for (i = 1; i <= 100; ++i)
	{
		if (useq[i] > useq[p])
		{
			p = i;
		}
	}
	return p;
}

int main()
{
	int i, j, k, iw, ik, n;
	scanf("%d", &n);
	memset(schedule, 0, sizeof(schedule));
	int fw, fd, fq;
	int w, d, q;
	
	scanf("%d%d%d", &fw, &fd, &fq);
	schedule[fw][fd] = fq;
	w = fw;
	d = fd;
	q = fq;
	for (i = 2; i <= n; ++i)
	{
		scanf("%d%d%d", &w, &d, &q);
		schedule[w][d] = q;
	}
	
	for (j = fd; j <= 7; ++j)
	{
		ans[1][j] = schedule[fw][j];
	}
	
	sans = -1;
	
	for (k = 1; k <= 4; ++k)
	{
		int sum(0);
		for (j = 1; j < fd; ++j)
		{
			memset(useq, 0, sizeof(useq));
			for (iw = fw + ik; iw < w; iw += k)
			{
				++useq[schedule[iw][j]];
			}
			if ((iw == w) && (j <= d))
			{
				++useq[schedule[iw][j]];
			}
			ans[1][j] = findmost();
			sum += useq[ans[1][j]];
		}
		for (j = fd; j <= 7; ++j)
		{
			for (iw = fw; iw < w; iw += k)
			{
				if (ans[1][j] == schedule[iw][j])
				{
					++sum;
				}
			}
			if ((iw == w) && (j <= d))
			{
				if (ans[1][j] == schedule[iw][j])
				{
					++sum;
				}
			}
		}
		for (ik = 2; ik <= k; ++ik)
		{
			memset(useq, 0, sizeof(useq));
			for (j = 1; j <= 7; ++j)
			{
				for (iw = fw + ik - 1; iw < w; iw += k)
				{
					++useq[schedule[iw][j]];
				}
				if ((iw == w) && (j <= d))
				{
					++useq[schedule[iw][j]];
				}
			}
			ans[ik][j] = findmost();
			sum += useq[ans[ik][j]];
		}
		if (sum > sans)
		{
			nans = k;
			sans = sum;
			memcpy(bans, ans, sizeof(ans));
		}
	}
	printf("%d\n", nans);
	for (i = 1; i <= nans; ++i)
	{
		for (int j = 1; j < 7; ++j)
		{
			printf("%d ", bans[i][j]);
		}
		printf("%d\n", bans[i][7]);
	}
	return 0;
}
