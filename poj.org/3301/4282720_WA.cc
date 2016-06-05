/*
 * PKU3301::Texas_Trip.cpp
 *
 *  Created on: Oct 27, 2008 6:36:56 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double esp = 1e-7;
const double pi = acos(0.0) * 2;

const int MAXN = 250000;

int nn(0);
double cv[MAXN];
double sv[MAXN];

int dblcmp(const double d)
{
	if (d < -esp) return -1;
	if (d > esp) return 1;
	return 0;
}

class Point
{
public:
	Point(const int xx = 0, const int yy = 0) :
		x(xx), y(yy)
	{
	}
	~Point(void)
	{
	}
	double x, y;
	double Dis(const Point &p) const
	{
		return sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
	}
	Point Rot(const double sin_val, const double cos_val) const
	{
		Point result;
		result.x = y * sin_val + x * cos_val;
		result.y = y * cos_val - x * sin_val;
		return result;
	}
};

Point points[64];
Point pp[64];
template <typename T_INT>
T_INT gcd(const T_INT &a_a, const T_INT &a_b)
{
	T_INT a(a_a);
	T_INT b(a_b);
	T_INT r;
	if (b > a)
	{
		std::swap(a, b);
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
	int tn;
	cin >> tn;
	cv[0] = 1;
	sv[0] = 0;
	nn = 1;
	for (int i = 1; i <= 160; ++i)
	{
		for (int j = 1; j <= 160; ++j)
		{
			if (gcd(i, j) != 1) continue;
			double dis = sqrt((double)((i * i) + (j * j)));
//			if (dis > 500.01) continue;
			cv[nn] = i / dis;
			sv[nn] = j / dis;
			++nn;
		}
	}
//	cerr << nn << endl;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &points[i].x, &points[i].y);
		}
		double mins(1e20);
		for (int i = 0; i < nn; ++i)
		{
			double minx(1e20), maxx(-1e20);
			double miny(1e20), maxy(-1e20);
			for (int k = 0; k < n; ++k)
			{
				pp[k] = points[k].Rot(sv[i], cv[i]);
//				cerr << pp[k].x << " " << pp[k].y << endl;
				minx = min(minx, pp[k].x);
				maxx = max(maxx, pp[k].x);
				miny = min(miny, pp[k].y);
				maxy = max(maxy, pp[k].y);
			}
			mins = min(mins, max((maxx - minx), (maxy - miny)) * max((maxx - minx), (maxy - miny)));
		}
		printf("%.2lf\n", mins);
	}
	return 0;
}


