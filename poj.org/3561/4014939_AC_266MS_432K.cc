#include <iostream>
#include <algorithm>

using namespace std;

char map[16][16];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int h, w;
		cin >> h >> w;
		for (int i = 0; i < h; ++i)
		{
			cin >> map[i];
		}
		bool flag(false);
		bool ans(false);
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] != '.')
				{
					if (flag)
					{
						ans = false;
					}
					else
					{
						flag = true;
						ans = true;
						int dx, dy;
						switch (map[i][j])
						{
							case '-':
							{
								dx = 0;
								dy = 1;
								break;
							}
							case '|':
							{
								dx = 1;
								dy = 0;
								break;
							}
							case '\\':
							{
								dx = 1;
								dy = 1;
								break;
							}
							case '/':
							{
								dx = 1;
								dy = -1;
								break;
							}
						}
						for (int x = i + dx, y = j + dy; (x < h) && (x >= 0) && (y < w) && (y >= 0); x += dx, y += dy)
						{
							if (map[x][y] != map[i][j])
							{
								break;
							}
							else
							{
								map[x][y] = '.';
							}
						}
					}
				}
			}
		}
		cout << (ans ? "CORRECT" : "INCORRECT") << endl;
	}
	return 0;
}
