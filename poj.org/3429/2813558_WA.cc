#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const double PRE = 1e-10;
const double BIG = 1e50;
const int SIZE = 1024;

int dblcmp(double d)
{
	if (d > PRE) return 1;
	if (d < -PRE) return -1;
	return 0;
}

class t_Point
{

	friend bool operator == (const t_Point &p1, const t_Point &p2)
	{
		return ((dblcmp(p1.x - p2.x) == 0) && (dblcmp(p1.y - p2.y) == 0));
	}
	friend bool operator < (const t_Point &p1, const t_Point &p2)
	{
		if (dblcmp(p1.x - p2.x) == 0)
		{
			return (p1.y < p2.y);
		}
		else
		{
			return (p1.x < p2.x);
		}
	}
	friend bool operator != (const t_Point &p1, const t_Point &p2)
	{
		return (!(p1 == p2));
	}
	friend t_Point operator + (const t_Point &p1,const t_Point &p2)
	{
		t_Point p3(p1);
		p3 += p2;
		return p3;
	}
	friend t_Point operator - (const t_Point &p1, const t_Point &p2)
	{
		t_Point p3(p1);
		p3 -= p2;
		return p3;
	}
	friend istream & operator >> (istream &in, t_Point &p1)
	{
		in >> p1.x >> p1.y;
		return in;
	}
	friend ostream & operator << (ostream &out, const t_Point &p1)
	{
		out << p1.x << ' ' << p1.y;
		return out;
	}
	friend double dist(const t_Point &p1, const t_Point &p2)
	{
		return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	}
	friend double dot(const t_Point &v1, const t_Point &v2)
	{
		return (v1.x * v2.x + v1.y * v2.y);
	}
	friend double dot(const t_Point &p0, const t_Point &p1, const t_Point &p2)
	{
		t_Point v1(p1 - p0);
		t_Point v2(p2 - p0);
		return dot(v1, v2);
	}
	friend int between(const t_Point &pc, const t_Point &pa, const t_Point &pb)
	{
		return dblcmp(dot(pc, pa, pb));
	}
	friend double det(const t_Point &v1, const t_Point &v2)
	{
		return (v1.x * v2.y - v1.y * v2.x);
	}
	friend double cross(const t_Point &p0, const t_Point &p1, const t_Point &p2)
	{
		return (det(p1 - p0, p2 - p0));
	}
	friend int segcross(const t_Point &a, const t_Point &b, const t_Point &c, const t_Point &d)
	{
		return (dblcmp(cross(a, c, d)) ^ dblcmp(cross(b, c, d))) == -2 &&
			   (dblcmp(cross(c, a, b)) ^ dblcmp(cross(d, a, b))) == -2;
	}
	//1 for regcross; 2 for inregcross; 3 for noncross 
	friend int segcross(const t_Point &a, const t_Point &b, const t_Point &c, const t_Point &d, t_Point &p)
	{
		double s1, s2, s3, s4;
		int d1, d2, d3, d4;
		d1 = dblcmp(s1 = cross(a, b, c));
		d2 = dblcmp(s2 = cross(a, b, d));
		d3 = dblcmp(s3 = cross(c, d, a));
		d4 = dblcmp(s4 = cross(c, d, b));
		if (((d1 ^ d2) == -2) && ((d3 ^ d4) == -2))
		{
			p.x = (c.x * s2 - d.x * s1) / (s2 - s1);
			p.y = (c.y * s2 - d.y * s1) / (s2 - s1);
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
	t_Point(const double new_x = 0.0, const double new_y = 0.0) :
		x(new_x), y(new_y)
	{
	}
	t_Point &operator += (const t_Point &p1)
	{
		x += p1.x;
		y += p1.y;
		return (*this);
	}
	t_Point &operator -= (const t_Point &p1)
	{
		x -= p1.x;
		y -= p1.y;
		return (*this);
	};
	double angle(void) const
	{
		return atan2(y, x);
	}
	double length(void) const
	{
		return (sqrt(x * x + y * y));
	}
	double x;
	double y;
};

class t_Segment
{
	friend istream & operator >> (istream &in, t_Segment &s1)
	{
		in >> s1.p1 >> s1.p2;
		return in;
	}
	friend ostream & operator << (ostream &out, const t_Segment &s1)
	{
		out << s1.p1 << ' ' << s1.p2;
		return out;
	}
	friend int between(const t_Point &pc, const t_Segment &sab)
	{
		return dblcmp(dot(pc, sab.p1, sab.p2));
	}	
	friend int segcross(const t_Segment &s1, const t_Segment &s2)
	{
		return segcross(s1.p1, s1.p2, s2.p1, s2.p2);
	}
	friend int segcross(const t_Segment &s1, const t_Segment &s2, t_Point &p)
	{
		return segcross(s1.p1, s1.p2, s2.p1, s2.p2, p);
	}
	
public:
	t_Segment(const t_Point &new_p1, const t_Point &new_p2)
	{
		p1 = new_p1;
		p2 = new_p2;
	}
	double length()
	{
		return (dist(p1, p2));
	}
	t_Point p1, p2;

};

t_Point ps[128];

int main()
{
	int i, n, m;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> ps[i];
	}
	int ans = 0;
	cin >> m;
	for (i = 1; i <= m; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		segcross(ps[a], ps[b], ps[c], ps[d], ps[n + i]);
		if (ps[n + i] == t_Point(0.0, 0.0))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}
