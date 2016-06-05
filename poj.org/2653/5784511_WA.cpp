/*
 * Pick-up_sticks.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

/*
 * cg.cpp
 *
 *  Created on: 2009-8-29
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const double PRE = 1e-10;

int dblcmp(const double d)
{
	if (d > PRE) return 1;
	if (d < -PRE) return -1;
	return 0;
}

class Point
{
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

	friend bool segcross(const Point &a, const Point &b, const Point &c, const Point &d)
	{
		return ((dblcmp(cross(a, c, d)) ^ dblcmp(cross(b, c, d))) == -2) &&
			   ((dblcmp(cross(c, a, b)) ^ dblcmp(cross(d, a, b))) == -2);
	}
	//1 for regcross; 2 for inregcross; 0 for noncross
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

	double m_x, m_y;
};

Point ps[100010][2];
int ans[1024];
Point cs;

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf", &ps[i][0].m_x, &ps[i][0].m_y, &ps[i][1].m_x, &ps[i][1].m_y);
		}
		ans[0] = 1;
		ans[1] = n - 1;
		for (int i = n - 2; i >= 0; --i)
		{
			bool flag = true;
			for (int j = 1; j <= ans[0]; ++j)
			{
				if (segcross(ps[i][0], ps[i][1], ps[ans[j]][0], ps[ans[j]][1], cs) == 1)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				ans[++ans[0]] = i;
			}
		}
		printf("Top sticks:");
		for (int i = ans[0]; i >= 1; --i)
		{
			printf(" %d%c", ans[i] + 1, (i == 1) ? '.' : ',');
		}
		printf("\n");
	}
	return 0;
}
