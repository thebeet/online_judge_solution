#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int h, w;
int mid;

int map[1024][1024];
bool gone[1024][1024];

void floodfill(queue< pair<int, int> > &q, const int x, const int y, const int s)
{
	if ((x >= 0) && (y >= 0) && (x < h) && (y < w) && (map[x][y] == -1))
	{
		map[x][y] = s;
		q.push(make_pair(x, y));
	}
}

void floodfill1(queue< pair<int, int> > &q, const int x, const int y, const int s)
{
	if ((x >= 0) && (y >= 0) && (x < h) && (y < w) && (map[x][y] >= mid) && (gone[x][y] == false))
	{
		gone[x][y] = true;
		q.push(make_pair(x, y));
	}
}

int check(const int x0, const int y0, const int x1, const int y1)
{
	queue< pair<int, int> > q[2];
	int p0(0), p1(1);
	int dis(0);
	memset(gone, false, sizeof(gone));
	q[p0].push(make_pair(x0, y0));
	gone[x0][y0] = true;
	while (q[p0].empty() == false)
	{
		if ((q[p0].front().first == x1) && (q[p0].front().second == y1))
		{
			break;
		}
		++dis;
		while (q[p1].empty() == false)
		{
			q[p1].pop();
		}
		while (q[p0].empty() == false)
		{
			floodfill1(q[p1], q[p0].front().first + 1, q[p0].front().second, dis);
			floodfill1(q[p1], q[p0].front().first - 1, q[p0].front().second, dis);
			floodfill1(q[p1], q[p0].front().first, q[p0].front().second + 1, dis);
			floodfill1(q[p1], q[p0].front().first, q[p0].front().second - 1, dis);
			q[p0].pop();
		}
		swap(p0, p1);
	}
	if (q[p0].empty() == false)
	{
		return dis;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		int x0, y0, x1, y1;
		queue< pair<int, int> > q[2];
		int p0(0), p1(1);
		memset(map, -1, sizeof(map));
		scanf("%d%d%d", &n, &h, &w);
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		for (int i = 0; i < n; ++i)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			q[p0].push(make_pair(x, y));
			map[x][y] = 0;
		}
		int dis(0);
		while (q[p0].empty() == false)
		{
			++dis;
			while (q[p1].empty() == false)
			{
				q[p1].pop();
			}
			while (q[p0].empty() == false)
			{
				floodfill(q[p1], q[p0].front().first + 1, q[p0].front().second, dis);
				floodfill(q[p1], q[p0].front().first - 1, q[p0].front().second, dis);
				floodfill(q[p1], q[p0].front().first, q[p0].front().second + 1, dis);
				floodfill(q[p1], q[p0].front().first, q[p0].front().second - 1, dis);
				q[p0].pop();
			}
			swap(p0, p1);
		}
		int lo = 0;
		int ans = abs(x0 - x1) + abs(y0 - y1);
		int hi = max(h, w);
		while (lo + 1 < hi)
		{
			mid = ((lo + hi) >> 1);
			int ret;
			if ((ret = check(x0, y0, x1, y1)) >= 0)
			{
				lo = mid;
				ans = ret;
			}
			else
			{
				hi = mid;
			}
		}
		cout << lo << " " << ans << endl;
	}
	return 0;
}

