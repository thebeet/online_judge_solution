/*
 * 4th_Point.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

class Point
{
public:
	Point(const int xx = 0, const int yy = 0) :
		x(xx), y(yy)
	{
	}
	int x, y;
};

istream &operator >> (istream &in, Point &p)
{
	double x, y;
	in >> x >> y;
	p.x = (int)(x * 1000.0 + 0.5);
	p.y = (int)(y * 1000.0 + 0.5);
	return in;
}

ostream &operator << (ostream &out, const Point &pt)
{
	Point p(pt);
	if (p.x < 0)
	{
		out << "-";
		p.x = -p.x;
	}
	out << p.x / 1000 << "." << setw(3) << setfill('0') << (p.x % 1000) << " ";
	if (p.y < 0)
	{
		out << "-";
		p.y = -p.y;
	}
	out << p.y / 1000 << "." << setw(3) << setfill('0') << (p.y % 1000) << endl;
	return out;
}

bool operator == (const Point &p1, const Point &p2)
{
	return (p1.x == p2.x) && (p1.y == p2.y);
}

Point operator + (const Point &p1, const Point &p2)
{
	return Point(p1.x + p2.x, p1.y + p2.y);
}

Point operator - (const Point &p1, const Point &p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y);
}

int main()
{
	Point r1, r2, t1, t2;
	while (cin >> r1 >> r2 >> t1 >> t2)
	{
		if (r1 == t2) swap(t1, t2);
		if (r2 == t1) swap(r1, r2);
		if (r2 == t2) { swap(t1, t2); swap(r1, r2); }
		cout << (r2 - r1 + t2);
	}
	return 0;
}
