#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	while ((cin >> n), n > 0)
	{
		long long i;
		long long num[32];
		long long s(0);
		for (i = 0; i < n; ++i)
		{
			double inp;
			cin >> inp;
			num[i] = (long long)(inp * 1000 + 0.1);
		}
		sort(num, num + n);
		for (i = 1; i < n; ++i)
		{
			s += num[i - 1];
			if (num[i] <= s) break;
		}
		if (i == n)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
