#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

const double PRE = 1e-8;
const double BIG = 1e50;
const int SIZE = 10010;

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
	t_Point(void)
	{
		x = 0.0;
		y = 0.0;
	}
	t_Point(const double new_x, const double new_y)
	{
		x = new_x;
		y = new_y;
	}
	virtual ~t_Point()
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
	double tan(void) const
	{
		if (y == 0)
		{
			return BIG;
		}
		else
		{
			return x / y;
		}
	}
	double length(void) const
	{
		return (sqrt(x * x + y * y));
	}
	double x;
	double y;
	char *inp;
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
	t_Segment(void)
	{
	}
	t_Segment(const t_Point &new_p1, const t_Point &new_p2)
	{
		p1 = new_p1;
		p2 = new_p2;
	}
	t_Point &getp1()
	{
		return p1;
	}
	t_Point &getp2()
	{
		return p2;
	}
	double length()
	{
		return (dist(p1, p2));
	}
	t_Point p1, p2;

private:
};

class t_Line /*    a * x + b * y + c = 0  a >= 0 */
{
	friend int linecross(t_Line &l1, t_Line &l2, t_Point &cp)
	{
		double d = l1.a * l2.b - l2.a * l1.b;
		if (dblcmp(d) == 0)
		{
			return 0;
		}
		else
		{
			cp.x = (l2.c * l1.b - l1.c * l2.b) / d;
			cp.y = (l2.a * l1.c - l1.a * l2.c) / d;
			return 1;
		}
	}

public:
	t_Line()
	{
		a = 0.0;
		b = 0.0;
		c = 0.0;
	}
	t_Line(double newa, double newb, double newc)
	{
		a = newa;
		b = newb;
		c = newc;
	}
	t_Line(t_Point &p1, t_Point &p2)
	{
		if ((p1.y - p2.y) > 0)
		{
			a = (p1.y - p2.y);
			b = -(p1.x - p2.x);
			c = -((p1.y - p2.y) * p1.x - (p1.x - p2.x) * p1.y);
		}
		else
		{
			a = -(p1.y - p2.y);
			b = (p1.x - p2.x);
			c = -(-(p1.y - p2.y) * p1.x + (p1.x - p2.x) * p1.y);
		}			
	}
	double a;
	double b;
	double c;
	
};

bool cmp(const t_Point &p1, const t_Point &p2)
{
	 if (dblcmp(p1.y - p2.y) == 0)
	 {
		 return (p1.x < p2.x);
	 }
	 else
	 {
		 return (p1.y < p2.y);
	 }
}

class t_Polygon
{
public:
	void Grahom_Scan(t_Polygon &conv)
	{
		int i;
		int stack[SIZE];
		sort(points + 1, points + 1 + size, cmp);
		stack[0] = 2;
		stack[1] = 1;
		stack[2] = 2;
		for (i = 3; i <= size; )
		{
			if (dblcmp(cross(points[stack[stack[0]]], points[stack[stack[0] - 1]], points[i])) < 0)
			{
				stack[++stack[0]] = i++;
			}
			else
			{
				--stack[0];
			}
		}
		stack[++stack[0]] = size - 1;
		for (i = size - 2; i >= 1; )
		{
			if (dblcmp(cross(points[stack[stack[0]]], points[stack[stack[0] - 1]], points[i])) < 0)
			{
				stack[++stack[0]] = i--;
			}
			else
			{
				--stack[0];
			}
		}
		for (i = 1; i <= stack[0]; ++i) //
		{
			conv.points[i] = points[stack[i]];
		}
		conv.size = stack[0]; //modify
	}
	
	double area()
	{
		double sum = 0.0;
		points[size + 1] = points[1];
		for (int i = 1; i <= size; ++i)
		{
			sum += det(points[i], points[i + 1]);
		}
		sum /= 2.0;
		return sum;
	}
	t_Point points[SIZE];
	int size;
};

t_Polygon inp, out;
char buf[320100];

int main()
{
	while (gets(buf) != NULL)
	{
		int i, n, dx;
		for (i = 0; i <= 4; ++i)
		{
			if (buf[i] == '\0')
			{
				break;
			}
		}
		if (i <= 4)
		{
			break;
		}
		
		n = 0;
		dx = 0;
		for ( ; ; )
		{
			/*while ((buf[dx] != '(') && (buf[dx] != '\0'))
			{
				++dx;
			}*/
			++n;
			inp.points[n].inp = buf + dx; 
			sscanf(inp.points[n].inp, "(%lf,%lf)", &inp.points[n].x, &inp.points[n].y);
			while (buf[++dx] != ')')
			{
			}
			if (buf[++dx] == '\0')
			{
					break;
			}
			buf[dx] = '\0';
			++dx;
		}
		
		--n;
		inp.size = n;
		inp.Grahom_Scan(out);
		for (i = 1; i <= out.size; ++i)
		{
			printf("%s%c", out.points[i].inp, (i == out.size) ? '\n' : ' ');
		}
	}
	return 0;
}
