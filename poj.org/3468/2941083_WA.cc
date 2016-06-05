#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define fmt "%lld"

long long nt[131072];
long long sum[131072];
long long nnt[1024];
long long allt[1024];
long long bsum[131072];

long long qq(int f, int t)
{
	int i;
	long long tot = sum[t] - sum[f - 1];
	int bf = (f >> 8) + 1;
	int bt = (t >> 8);
	int ef = bf << 8;
	int et = bt << 8;
	if (ef > t)
	{
		ef = f;
		et = f;
	}
	for (i = f; i < ef; ++i)
	{
		tot += bsum[i] + allt[i >> 8];
	}
	for (i = bf; i < bt; ++i)
	{
		tot += nnt[i];
	}
	for (i = et; i <= t; ++i)
	{
		tot += bsum[i] + allt[i >> 8];
	}
	return tot;
}

void cc(int f, int t, int c)
{
	int i;
	int bf = (f >> 8) + 1;
	int bt = (t >> 8);
	int ef = bf << 8;
	int et = bt << 8;
	if (ef > t)
	{
		ef = f;
		et = f;
	}
	for (i = f; i < ef; ++i)
	{
		bsum[i] += c;
		nnt[i >> 8] += c;
	}
	nnt[bf - 1] += c;
	for (i = bf; i < bt; ++i)
	{
		nnt[i] += c << 8;
		allt[i] += c;
	}
	for (i = et; i <= t; ++i)
	{
		bsum[i] += c;
		nnt[i >> 8] += c;
	}
}

int main()
{
	char op[4];
	int i, n, q, f, t;
	long long c;
	cin >> n >> q;
	for (i = 1; i <= n; ++i)
	{
		scanf(fmt, &nt[i]);
		sum[i] = sum[i - 1] + nt[i]; 
	}
	for (i = 1; i <= q; ++i)
	{
		scanf("%s%d%d", op, &f, &t);
		if (op[0] == 'Q')
		{
			printf(fmt "\n", qq(f, t));
		}
		else
		{
			scanf(fmt, &c);
			cc(f, t, c);
		}
	}
	return 0;
}
