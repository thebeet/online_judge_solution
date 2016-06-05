#include <iostream>

using namespace std;

long long calc(long long n)
{
	long long tn = n;
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
	while (tn >= 10)
	{
		tn /= 10;
		d *= 10;
		++l;
	}
	long long ret1 = calc(n - d * tn);
	long long ret2 = calc(d - 1);
	if (tn == 1)
	{
		return ret1 + ret2 + (n - d * tn + 1);
	}
	else
	{
		return ret2 * tn + d + ret1;
	}
}

int main()
{
	long long n;
	while (cin >> n)
	{
		long long lo = 1;
		long long hi = 999999999999999999LL;
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
	}
	return 0;
}
