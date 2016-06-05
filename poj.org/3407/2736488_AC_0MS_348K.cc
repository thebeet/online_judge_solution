#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const double pi = 2.0 * acos(0);

int main()
{
	double px1, py1, px2, py2;
	double x1, xd1, y1, yd1;
	double dx1, dy1;
	string p1, p2;
	cin >> x1 >> xd1 >> p1 >> y1 >> yd1 >> p2;
	x1 += xd1 / 60.0;
	y1 += yd1 / 60.0;
	if (p1 == "N")
	{
		x1 += 90.0;
	}
	else
	{
		x1 = 90.0 - x1;
	}
	
	if (p2 == "W")
	{
		y1 += 180.0;
	}
	else
	{
		y1 = 180.0 - y1;
	}
	px1 = x1;
	py1 = y1;
	cin >> x1 >> xd1 >> p1 >> y1 >> yd1 >> p2;
	x1 += xd1 / 60.0;
	y1 += yd1 / 60.0;
	if (p1 == "N")
	{
		x1 += 90.0;
	}
	else
	{
		x1 = 90.0 - x1;
	}
	
	if (p2 == "W")
	{
		y1 += 180.0;
	}
	else
	{
		y1 = 180.0 - y1;
	}
	px2 = x1;
	py2 = y1;
	dy1 = abs(py2 - py1) / 180.0 * pi;
	px1 = px1 / 180.0 * pi;
	px2 = px2 / 180.0 * pi;
	double ca = cos(px1) * cos(px2) + sin(px1) * sin(px2) * cos(dy1);
	double da = acos(ca);
	printf("%.3lf\n", da * 6370.0);
	return 0;
}
