#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

const double esp = 0.000000001;
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
	cin >> s;
	double lo(0.0), hi(10000.0);
	while (lo + esp < hi)
	{
		double mid((lo + hi) / 2.0);
		((calc_v(mid) < calc_v(mid + esp)) ? lo : hi) = mid;
	}
	cout.setf(ios::fixed); 
	cout.precision(2);
	cout << calc_v(lo) << endl << h << endl << lo << endl;
	return 0;
}
