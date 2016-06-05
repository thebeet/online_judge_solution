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
	unsigned long long i, n, k, x, m;
	while (cin >> n >> x >> k)
	{
		unsigned long long g(0);
		cin >> g;
		for (i = 2; i <= n; ++i)
		{
			cin >> m;
			g = gcd(g, m);
		}
		if (((x * k) % g) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
