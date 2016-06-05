#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct point
{
	int x, y;
};

typedef pair<point, point> pp;

point p[256];

bool operator < (const pp &p1, const pp &p2)
{
	int x1 = p1.second.x - p1.first.x;
	int y1 = p1.second.y - p1.first.y;
	int x2 = p2.second.x - p2.first.x;
	int y2 = p2.second.y - p2.first.y;
	double k1, k2;
	if (x1 == 0)
	{
		k1 = 2000;
	}
	else
	{
		k1 = (double)y1 / x1;
	}
	if (x2 == 0)
	{
		k2 = 2000;
	}
	else
	{
		k2 = (double)y2 / x2;
	}
	return (k1 + 0.0000001 < k2);
}

int main()
{
	int i, j, n, m;
	cin >> n;
	map<pp, bool> pps;
	cout << pps.size() << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> p[i].x >> p[i].y;
		for (int j = 0; j < i; ++j)
		{
			pps[make_pair(p[j], p[i])] = true;
		}
	}
	cout << pps.size() << endl;
	
	return 0;
}
