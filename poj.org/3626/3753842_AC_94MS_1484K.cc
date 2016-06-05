#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool map[1024][1024];

int x, y, n;

bool check(const pair<int, int> p)
{
	if ((p.first < -500) || (p.first > 500) || (p.second < -500) || (p.second > 500))
	{
		return false;
	}
	bool ret = map[p.first  + 512][p.second  + 512];
	map[p.first  + 512][p.second  + 512] = false;
	return ret;
}

int findxy(const int x, const int y)
{
	queue< pair<int, int> > q[2];
	q[0].push(make_pair(0, 0));
	map[512][512] = false;
	int p0(0), p1(1);
	int ans(0);
	while (map[512 + x][512 + y])
	{
		++ans;
		while (q[p0].empty() == false)
		{
			pair<int, int> co = q[p0].front();
			q[p0].pop();
			pair<int, int> tco(co);
			++tco.first;
			if (check(tco))
			{
				q[p1].push(tco);
			}
			tco = co;
			--tco.first;
			if (check(tco))
			{
				q[p1].push(tco);
			}
			tco = co;
			++tco.second;
			if (check(tco))
			{
				q[p1].push(tco);
			}
			tco = co;
			--tco.second;
			if (check(tco))
			{
				q[p1].push(tco);
			}
		}
		swap(p0, p1);
	}
	return ans;
}

int main()
{
	cin >> x >> y >> n;
	memset(map, true, sizeof(map));
	for (int i = 0; i < n; ++i)
	{
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		map[xx + 512][yy + 512] = false;
	}
	cout << findxy(x, y) << endl; 
	return 0;
}
