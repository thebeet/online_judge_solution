#include <iostream>

using namespace std;

long long calc2[128];

long long calc(long long n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n < 10)
	{
		return 1;
	}
	long long l = 0;
	long long d = 1;
	long long tn = n;
	while (tn >= 10)
	{
		tn /= 10;
		d *= 10;
		++l;
	}
	long long m = n - d * tn;
	long long ret1 = calc(m);
	long long ret2 = calc2[l];
	if (tn == 1)
	{
		return ret1 + ret2 + (m + 1);
	}
	else
	{
		return ret2 * tn + d + ret1;
	}
}

int main()
{
	long long n, m;
	
	cin >> n;
	m = 1;
	calc2[1] = 1;
	for (int i = 2; i <= 17; ++i)
	{
		m *= 10;
		calc2[i] = i * m;
	}
	long long lo = 1;
	long long hi = 599999999999999999LL;
	while (lo + 1 < hi)
	{
		long long mid = (lo + hi) / 2;
		long long ret = calc(mid);
		((ret > n) ? hi : lo) = mid;
	}
	if (calc(lo) == n)
	{
		while (calc(lo - 1) == n)
		{
			--lo;
		}
		cout << lo << endl;
	}
	else
	{
		cout << "Petr lies" << endl;
	}
	return 0;
}
