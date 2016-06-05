#include <iostream>
#include <algorithm>

using namespace std;

struct Point
{
	int x, y;
};

bool comp1(const Point &p1, const Point &p2)
{
	return (p1.x < p2.x); 
}

bool comp2(const Point &p1, const Point &p2)
{
	return (p1.y < p2.y); 
}

Point points[256];
Point pointsy[256];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 0; ti < tn; ++ti)
	{
		int ans(0x3fffffff);
		int n, m;
		scanf("%d%d", &n, &m);
		memset(points, 0, sizeof(points));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d", &points[i].x, &points[i].y);
		}
		sort(points, points + n, comp1);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + m - 1; j < n; ++j)
			{
				if (points[j].x == points[j + 1].x) continue;
				int w = (points[j].x - points[i].x + 2); 
				memcpy(pointsy, points, sizeof(points));
				sort(pointsy + i, pointsy + j + 1, comp2);
				for (int k = i + m - 1; k <= j; ++k)
				{
					int h = (pointsy[k].y - pointsy[k - m + 1].y + 2);
					ans = min(ans, w * h);
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
