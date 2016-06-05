#include <iostream>
#include <algorithm>

using namespace std;

long long mi_mod(long long a, long long p)
{
	long long y(p);
	long long ans(1);
	long long t(a);
	while (y > 0)
	{
		if (y & 1)
		{
			(ans *= t) %= p;
		}
		(t *= t) %= p;
		y >>= 1;
	}
	return ans;
}

int main()
{
	long long a, p;
	while ((cin >> p >> a), p > 0)
	{
		long long i;
		for (i = 2; i * i <= p; ++i)
		{
			if ((p % i) == 0)
			{
				break;
			}
		}
		if (i * i > p)
		{
			cout << "no" << endl;
			continue;
		}
		if (mi_mod(a, p) == a)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	return 0;
}
