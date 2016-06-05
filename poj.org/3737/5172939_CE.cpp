#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double pi = acos(0) * 2;
double l;
double h;
double s;
double calc_v(const double r)
{
		l = s / pi / r - r;
		h = sqrt(l * l - r * r);
		double v = r * r * pi * h / 3;
		return v;
}

int main()
{
	while(cin >> s)
	{
	double r = sqrt(s / 4.0 / pi);
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << calc_v(r) << endl << h << endl << r << endl;
	}
	return 0;
}
