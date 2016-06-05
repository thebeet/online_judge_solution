#include <iostream>
#include <algorithm>

using namespace std;

const long long HIe(0x10000LL);
const long long MASK(0xFFFFLL);
int main()
{
	long long i, x, y, z;
	while (cin >> x >> y >> z)
	{
		long long lo(0), hi(0);
		long long st = x - z;
		long long hist = (x | MASK);
		long long s(0);
		long long pres(0);
		for (i = hist; i < y; i += HIe)
		{
			pres = s;
			s = (i - st) / z;
			if ((s - pres) & 1)
			{
				hi ^= (i >> 16);
			}
		}
		pres = s;
		s = (y - st) / z;
		if ((s - pres) & 1)
		{
			hi ^= (y >> 16);
		}
		long long savelo(0);
		for (long long j = 0, i = x; j < HIe; ++j, i += z)
		{
			if (j == (s & MASK))
			{
				savelo = lo;
			}
			lo ^= i;
		}
		if (s & 1)
		{
			(lo ^= savelo) &= MASK;
		}
		else
		{
			lo = (savelo & MASK);
		}
		cout << (hi << 16) + lo << endl;
	}
	return 0;
}
