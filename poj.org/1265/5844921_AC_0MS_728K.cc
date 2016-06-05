/*
 * Area.cpp
 *
 *  Created on: 2009-9-11
 *      Author: thebeet
 */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const double PRE = 1e-8;

int dblcmp(const double d)
{
	if (d > PRE) return 1;
	if (d < -PRE) return -1;
	return 0;
}

class Point
{
	friend istream &operator >> (istream &in, Point &p)
	{
		return in >> p.m_x >> p.m_y;
	}

	friend Point operator + (const Point &p1, const Point &p2)
	{
		return Point(p1.m_x + p2.m_x, p1.m_y + p2.m_y);
	}

	friend Point operator - (const Point &p1, const Point &p2)
	{
		return Point(p1.m_x - p2.m_x, p1.m_y - p2.m_y);
	}

	friend bool operator == (const Point &p1, const Point &p2)
	{
		return ((dblcmp(p1.m_x - p2.m_x) == 0) && (dblcmp(p1.m_y - p2.m_y) == 0));
	}

	friend double dist(const Point &p1, const Point &p2)
	{
		return sqrt((p1.m_x - p2.m_x) * (p1.m_x - p2.m_x) + (p1.m_y - p2.m_y) * (p1.m_y - p2.m_y));
	}

	friend double dot(const Point &v1, const Point &v2)
	{
		return (v1.m_x * v2.m_x + v1.m_y * v2.m_y);
	}

	friend double dot(const Point &p0, const Point &p1, const Point &p2)
	{
		Point v1(p1.m_x - p0.m_x, p1.m_y - p0.m_y);
		Point v2(p2.m_x - p0.m_x, p2.m_y - p0.m_y);
		return dot(v1, v2);
	}

	friend int between(const Point &pc, const Point &pa, const Point &pb)
	{
		return dblcmp(dot(pc, pa, pb));
	}

	friend double det(const Point &v1, const Point &v2)
	{
		return (v1.m_x * v2.m_y - v1.m_y * v2.m_x);
	}

	friend double cross(const Point &p0, const Point &p1, const Point &p2)
	{
		Point v1(p1.m_x - p0.m_x, p1.m_y - p0.m_y);
		Point v2(p2.m_x - p0.m_x, p2.m_y - p0.m_y);
		return (det(v1, v2));
	}

	friend int segcross(const Point &a, const Point &b, const Point &c, const Point &d)
	{
		return (dblcmp(cross(a, c, d)) ^ dblcmp(cross(b, c, d))) == -2 &&
			   (dblcmp(cross(c, a, b)) ^ dblcmp(cross(d, a, b))) == -2;
	}
	//1 for regcross; 2 for inregcross; 3 for noncross
	friend int segcross(const Point &a, const Point &b, const Point &c, const Point &d, Point &p)
	{
		double s1, s2, s3, s4;
		int d1, d2, d3, d4;
		d1 = dblcmp(s1 = cross(a, b, c));
		d2 = dblcmp(s2 = cross(a, b, d));
		d3 = dblcmp(s3 = cross(c, d, a));
		d4 = dblcmp(s4 = cross(c, d, b));
		if (((d1 ^ d2) == -2) && ((d3 ^ d4) == -2))
		{
			p.m_x = (c.m_x * s2 - d.m_x * s1) / (s2 - s1);
			p.m_y = (c.m_y * s2 - d.m_y * s1) / (s2 - s1);
			return 1;
		}
		if ((d1 == 0 && between(c, a, b) <= 0) ||
		    (d2 == 0 && between(d, a, b) <= 0) ||
		    (d3 == 0 && between(a, c, d) <= 0) ||
		    (d4 == 0 && between(b, c, d) <= 0) )
		{
			return 2;
		}
		return 0;
	}
public:
	Point(const double x = 0.0, const double y = 0.0) :
		m_x(x), m_y(y)
	{
	}

private:
	double m_x, m_y;
};

class Segment
{
	friend int between(const Segment &sab, const Point &pc)
	{
		return dblcmp(dot(pc, sab.m_p1, sab.m_p2));
	}
	friend int segcross(const Segment &s1, const Segment &s2)
	{
		return segcross(s1.m_p1, s1.m_p2, s2.m_p1, s2.m_p2);
	}
	friend int segcross(const Segment &s1, const Segment &s2, Point &p)
	{
		return segcross(s1.m_p1, s1.m_p2, s2.m_p1, s2.m_p2, p);
	}

public:
	Segment(const Point &p1 = Point(), const Point &p2 = Point()) :
		m_p1(p1), m_p2(p2)
	{
	}

private:
	Point m_p1, m_p2;
};

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

class Polygon
{
public:
	// 1 for at Vertex; 2 for at edge; 3 for inside; 0 for outside
	bool isin(Point &p1) const
	{
		//TODO
		return false;
	}

/*	void Grahom_Scan(Polygon &conv) //?
	{
		int i;
		int stack[m_vertexs.size()];
		sort(m_vertexs.begin(), m_vertexs.end());
		stack[0] = 2;
		stack[1] = 1;
		stack[2] = 2;
		for (i = 3; i <= size; )
		{
			int ret = dblcmp(cross(vertexs[stack[stack[0]]], vertexs[stack[stack[0] - 1]], vertexs[i]));
			if (ret > 0)
			{
				stack[++stack[0]] = i++;
			}
			else if (ret == 0)
			{
				stack[stack[0]] = i++;
			}
			else
			{
				--stack[0];
			}
		}
		stack[++stack[0]] = size - 1;
		for (i = size - 2; i >= 1; )
		{
			int ret = dblcmp(cross(vertexs[stack[stack[0]]], vertexs[stack[stack[0] - 1]], vertexs[i]));
			if (ret > 0)
			{
				stack[++stack[0]] = i--;
			}
			else if (ret == 0)
			{
				stack[stack[0]] = i--;
			}
			else
			{
				--stack[0];
			}
		}
		for (i = 1; i < stack[0]; ++i)
		{
			conv.vertexs[i] = vertexs[stack[i]];
		}
		conv.size = stack[0] - 1;
	}
*/

	double area()
	{
		double sum(0.0);
		for (int i = 0; i < m_vertexs.size(); ++i)
		{
			sum += det(m_vertexs[i], m_vertexs[(i + 1) % m_vertexs.size()]);
		}
		sum /= 2.0;
		return sum;
	}

	int Input()
	{
		int n;
		cin >> n;
		int sum(0);
		m_vertexs.resize(n);
		m_vertexs[0] = Point(0.0, 0.0);
		for (int i = 1; i <= n; ++i)
		{
			int xx, yy;
			cin >> xx >> yy;
			if (i < n)
			{
				m_vertexs[i] = m_vertexs[i - 1] + Point(xx, yy);
			}
			xx = abs(xx); yy = abs(yy);
			int g = gcd(xx, yy);
			sum += g;
		}
		return sum;
	}

private:
	vector<Point> m_vertexs;
};

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 1; ti <= tn; ++ti)
	{
		Polygon p;
		int s = p.Input();
		double area = p.area();
		cout << "Scenario #" << ti << ":" << endl;

		cout << (int)(area + 1 - (double)s / 2 + PRE) << " " << s << " " << fixed << setprecision(1) << area << endl;
		if (ti < tn) cout << endl;
	}
	return 0;
}
