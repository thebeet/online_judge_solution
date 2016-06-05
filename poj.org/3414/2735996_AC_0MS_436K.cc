#include <iostream>
#include <algorithm>

using namespace std;

int tans[16384];
int queue[16384];
int way[16384];

int ans[16384];

int a, b, c;

int fill(int p, int st)
{
	if (p == 1)
	{
		return ((a << 7) + (st & 127));
	}
	else
	{
		return (st & 16256) + b;
	}
}

int drop(int p, int st)
{
	if (p == 3)
	{
		return (st & 127);
	}
	else
	{
		return (st & 16256);
	}
}

int pour(int p, int st)
{
	int x = st >> 7;
	int y = st & 127;
	if (p == 5)
	{
		if ((x + y) > b)
		{
			return ((x + y - b) << 7) + b;
		}
		else
		{
			return (x + y);
		}
	}
	else
	{
		if ((x + y) > a)
		{
			return (a << 7) + (x + y - a);
		}
		else
		{
			return (x + y) << 7;
		}
	}
}

int trans(int way, int st)
{
	switch (way)
	{
	case 1: case 2:
		{
			return fill(way, st);
		}
	case 3: case 4:
		{
			return drop(way, st);
		}
	case 5: case 6:
		{
			return pour(way, st);
		}
	}
}

int main()
{
	cin >> a >> b >> c;
	int i;
	queue[0] = 1;
	queue[1] = 0;
	memset(tans, 1, sizeof(tans));
	tans[0] = 0;
	if (c > 0)
	{
		for (i = 1; i <= queue[0]; ++i)
		{
			int ret, w;
			for (w = 1; w <= 6; ++w)
			{
				ret = trans(w, queue[i]);
				if (tans[ret] > 100000)
				{
					queue[++queue[0]] = ret;
					tans[ret] = queue[i];
					way[ret] = w;
					if (((ret & 127) == c) || ((ret >> 7) == c))
					{
						break;
					}
				}
			}
			if (w <= 6)
			{
				break;
			}
		}
	}
	else
	{
		i = 0;
	}
	if (i <= queue[0])
	{
		ans[0] = 0;
		int p = queue[queue[0]];
		while (p != 0)
		{
			ans[++ans[0]] = way[p];
			p = tans[p];
		}
		cout << ans[0] << endl;
		for (i = ans[0]; i >= 1; --i)
		{
			switch (ans[i])
			{
			case 1: case 2:
				cout << "FILL(" << ans[i] << ")" << endl;
				break;
			case 3: case 4:
				cout << "DROP(" << ans[i] - 2 << ")" << endl;
				break;
			case 5: case 6:
				cout << "POUR(" << ans[i] - 4 << ',' << 1 + ((ans[i] - 5) ^ 1) << ")" << endl;
				break;
			}
		}
	}
	else
	{
		cout << "impossible" << endl;
	}
	return 0;
}
