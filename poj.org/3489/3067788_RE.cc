#include <iostream>
#include <algorithm>

using namespace std;

template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (b > a)
	{
		swap(a, b);
	}
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	unsigned long long i, n, k, x;
	unsigned long long num[1024];
	while (cin >> n >> x >> k)
	{
		unsigned long long g(0);
		for (i = 1; i <= n; ++i)
		{
			cin >> num[i];
			g = gcd(g, num[i]);
		}
		if (((x * k) % g) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
