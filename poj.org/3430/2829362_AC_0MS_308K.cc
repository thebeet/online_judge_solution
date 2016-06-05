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
	/*
	cout << "####################" << endl;
	for (i = 0; i <= 4; ++i)
	{
		cout << useq[i] << " ";
	}
	cout << endl << "####################" << endl;
	//*/
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
	
	sans = -1;
	
	for (k = 1; k <= 4; ++k)
	{
		int sum(0);
		for (ik = 1; ik <= k; ++ik)
		{
			for (j = 1; j <= 7; ++j)
			{
				memset(useq, 0, sizeof(useq));
				int st = fw + ik - 1;
				if ((st == fw) && (j < fd))
				{
					st = fw + k;
				}
				for (iw = st; iw < w; iw += k)
				{
					++useq[schedule[iw][j]];
				}
				if ((iw == w) && (j <= d))
				{
					++useq[schedule[iw][j]];
				}
				ans[ik][j] = findmost();
				sum += useq[ans[ik][j]];
			}
		}
		if (sum > sans)
		{
			nans = k;
			sans = sum;
			memcpy(bans, ans, sizeof(ans));
		}
	}
	printf("%d\n", nans);
	//printf("%d\n", sans);
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
