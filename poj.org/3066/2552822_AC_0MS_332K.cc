#include <iostream>
#include <cmath>

using namespace std;

double mypow(const double x, const int y)
{
	double ans = 1.0;
	for (int i = 1; i <= y; ++i)
	{
		ans *= x;
	}
	return ans;
}

int main()
{
	int m, p;
	double a, b;
	while (cin >> m >> p >> a >> b)
	{
		double sum;
		double hia = sqrt(a);
		double loa = -1.0 / hia;
		int x1 = (int)((b * hia - m * loa) / (hia - loa));
		int x2 = (int)((b * hia - m * hia) / (loa - hia));
		sum = x1 * mypow(hia, p) + x2 * mypow(loa, p);
		if (x1 + x2 < m)
		{
			sum += mypow(b * hia - x1 * hia - x2 * loa, p);
		}
		cout << (int)(sum + 0.5) << endl;
	}
	return 0;
}
