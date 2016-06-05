#include <iostream>

using namespace std;

typedef long long INT;

INT A[16][16];
INT C[16][16];
INT ans[16];
INT breaknum[16];
INT sums[16];

void breakup(int p, int n, int st)
{
	INT i;
	if (n == 0)
	{
		INT sum = 1;
		INT tot = 0;
		INT todiv = 1;
		INT rest = p;
		for (i = st; i <= rest; ++i)
		{
			for (INT j = 1; j <= breaknum[i]; ++j)
			{
				sum *= C[rest][i];
				rest -= i;
			}
			tot += breaknum[i];
			todiv *= A[breaknum[i]][breaknum[i]];
		}
		sum = (A[tot][tot] / todiv) * sum;
		ans[p] += sum;
		return;
	}
	if (st > n)
	{
		st = n;
	}
	for (i = st; i >= 1; --i)
	{
		++breaknum[i];
		breakup(p, n - i, i);
		--breaknum[i];
	}
}

int main()
{
	INT i, j;
	A[0][0] = 1;
	C[0][0] = 1;
	for (i = 1; i <= 13; ++i)
	{
		A[i][0] = 1;
		C[i][0] = 1;
		for (j = 1; j <= i; ++j)
		{
			A[i][j] = A[i][j - 1] * (i - j + 1);
			C[i][j] = C[i][j - 1] * (i - j + 1) / j;
		}
	}
	
	memset(ans, 0, sizeof(ans));
	memset(breaknum, 0, sizeof(breaknum));
	memset(sums, 0, sizeof(sums));
	
	for (i = 1; i <= 13; ++i)
	{
		breakup(i, i, i);
	}
	for (i = 1; i <= 13; ++i)
	{
		for (j = 1; j <= i; ++j)
		{
			sums[i] += ans[j] * C[i][j];
		}
	}
	int tn, ti, n;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		cin >> n;
		cout << ti << " " << n << " " << sums[n] << endl;
	}
	return 0;
}
