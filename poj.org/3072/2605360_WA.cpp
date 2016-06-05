#include <iostream>
#include <cmath>

using namespace std;

const int MAXN = 5010;
const double PRE = 1e-8;
const double BIG = 1e50;
const double PI = acos(0.0) * 2.0;

int r, n;

int dblcmp(double d)
{
	if (d > PRE) return 1;
	if (d < -PRE) return -1;
	return 0;
}

class t_Point
{
	friend double ang(const t_Point &p0, const t_Point &p1, const t_Point &p2)
	{
		t_Point tp1 = p1 - p0;
		t_Point tp2 = p2 - p0;
		return (fabs(tp1.angle() - tp2.angle()) * 180.0 / PI);
	}
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

class t_data
{
	friend bool operator < (t_data d1,t_data d2)
	{
		return (d1.weight < d2.weight);
	}
public:
	double weight;
	int data1, data2;
};

class t_heap
{
	public:
		t_heap(int n)
		{
			 data = new t_data[n];
			 memset(data, 0, sizeof(t_data) * n);
			 t_heapsize = 0;
		}
		int getsize()
		{
			return t_heapsize;
		}
		void insert(t_data newdata)
		{
			data[++t_heapsize] = newdata;
			turnup(t_heapsize);
		}
		t_data &gettop()
		{
			return data[1];
		}
		void deletetop()
		{
			swap(data[1], data[t_heapsize--]);
			turndown(1);
		}
		void clean()
		{
			t_heapsize = 0;
		}
	private:
		int t_heapsize;
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[p] < data[nextp])
				{
					swap(data[nextp], data[p]);
					turnup(nextp);
				}
			}
		}
		void turndown(int p)
		{
			int nextp = (p << 1);
			if (nextp <= t_heapsize)
			{
				if ((nextp < t_heapsize) && (data[nextp + 1] < data[nextp]))
				{
					++nextp;
				}
				if (data[nextp] < data[p])
				{
					swap(data[nextp], data[p]);
					turndown(nextp);
				}
			}
		}
};

t_heap heap(MAXN);

bool gone[32][32];
t_Point points[32];

// dijkstra use heap 
int dijkstra(int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, sizeof(gone));
	for (int i = 2; i <= n; ++i)
	{
		new_data.weight = ang(points[1], points[i], points[n]);
		new_data.data1 = 1;
		new_data.data2 = i;
		heap.insert(new_data);
	}
	while (true)
	{
		while ((heap.getsize() != 0) && (gone[heap.gettop().data1][heap.gettop().data2] == true))
		{
			heap.deletetop();
		}
		if (heap.getsize() == 0)
		{
			break;
		}
		st_data = heap.gettop();
		gone[st_data.data1][st_data.data2] = true;
		if (st_data.data1 == pend) break;
		double dis = dist(points[st_data.data1], points[st_data.data2]);
		if (dis - PRE > r)
		{
			continue;
		}
		double a1 = (points[st_data.data2] - points[st_data.data1]).angle();
		new_data.data1 = st_data.data2;
		if (st_data.data2 == pend)
		{
			new_data.weight = st_data.weight + dis;
			new_data.data2 = 0;
			heap.insert(new_data);
		}
		else
		{
			for (int i = 1; i <= n; ++i)
			{
				if ((gone[st_data.data2][i] == false) && (i != st_data.data2))
				{
					double a2 = (points[i] - points[st_data.data2]).angle();
					new_data.weight = st_data.weight + dis + fabs(a1 - a2) * 180.0 / PI;
					new_data.data2 = i;
					heap.insert(new_data);
				}
			}
		}
	}
	if (heap.getsize() == 0)
	{
		return -1;
	}
	else
	{
		return (int)(st_data.weight + 0.5000000001);
	}
}

int main()
{
	while ((cin >> r >> n), r >= 0)
	{
		int i;
		heap.clean();
		for (i = 1; i <= n; ++i)
		{
			cin >> points[i];
		}
		int ret = dijkstra(n);
		if (ret == -1)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << dijkstra(n) << endl;
		}
	}
	return 0;
}
