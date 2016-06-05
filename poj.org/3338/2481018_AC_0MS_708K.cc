#include <iostream>

using namespace std;

bool map[25][25][25][25];
bool gone[25][25];

void swap(int &d1, int &d2)
{
	int tmp = d1;
	d1 = d2;
	d2 = tmp;
}

void fill(int x, int y)
{
	gone[x][y] = true;
	if ((gone[x + 1][y] == false) && (map[x][y][x + 1][y] == false))
	{
		fill(x + 1, y);
	}
	if ((gone[x - 1][y] == false) && (map[x][y][x - 1][y] == false))
	{
		fill(x - 1, y);
	}
	if ((gone[x][y + 1] == false) && (map[x][y][x][y + 1] == false))
	{
		fill(x, y + 1);
	}
	if ((gone[x][y - 1] == false) && (map[x][y][x][y - 1] == false))
	{
		fill(x, y - 1);
	}
}

int main()
{
	int w, h;
	while (cin >> h >> w, w > 0)
	{
		int i, n, x1, x2, y1, y2, x, y, ans;
		cin >> n;
		memset(map, false, sizeof(map));
		memset(gone, true, sizeof(gone));
		for (x = 1; x <= w; ++x)
		{
			for (y = 1; y <= h; ++y)
			{
				gone[x][y] = false;
			}
		}
		for (i = 1; i <= n; ++i)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x2 < x1)
			{
				swap(x1, x2);
			}
			if (y2 < y1)
			{
				swap(y1, y2);
			}
			for (x = x1 + 1; x <= x2; ++x)
			{
				map[x][y1][x][y1 + 1] = true; 
				map[x][y1 + 1][x][y1] = true;
				map[x][y2][x][y2 + 1] = true;
				map[x][y2 + 1][x][y2] = true;
			}
			for (y = y1 + 1; y <= y2; ++y)
			{
				map[x1][y][x1 + 1][y] = true;
				map[x1 + 1][y][x1][y] = true;
				map[x2][y][x2 + 1][y] = true;
				map[x2 + 1][y][x2][y] = true;
			}
		}
		ans = 0;
		for (x = 1; x <= w; ++x)
		{
			for (y = 1; y <= h; ++y)
			{
				if (gone[x][y] == false)
				{
					fill(x, y);
					++ans;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
