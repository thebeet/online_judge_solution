#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
int mm;
char map[32][64];

int ans[64][32][64];

char getmap(int t, int x, int y)
{
	t %= m;
	if ((x == 0) || (x == n - 1))
	{
		return map[x][y];
	}
	else
	{
		if ((x & 1) == 0)
		{
			return (map[x][(y + t) % m]);
		}
		else
		{
			return (map[x][(y - t + mm) % m]);
		}
	}
}

struct t_queue
{
	void init()
	{
		tot = 0;
	}
	void add(int new_t, int new_x, int new_y)
	{
		t[++tot] = new_t;
		x[tot] = new_x;
		y[tot] = new_y;
	}
	void go(int new_t, int new_x, int new_y, int pr)
	{
		if ((new_x >= 0) && (new_y >= 0) && (new_x < n) && (new_y < m) && (ans[new_t % m][new_x][new_y] > 65536) && (getmap(new_t, new_x, new_y) != 'X'))
		{
			ans[new_t % m][new_x][new_y] = pr;
			add(new_t, new_x, new_y);
		}
	}
	int tot;
	int t[65536];
	int x[65536];
	int y[65536];
}queue;

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, tt;
		int st, ed;
		int totstep;
		memset(map, 'X', sizeof(map));
		
		scanf("%d", &totstep);
		scanf("%d%d", &n, &m);
		n += 2;
		mm = m * 10000000;
		for (i = n - 1; i >= 0; --i)
		{
			scanf("%s", map[i]);
		}
		
		/* find start and end */
		for (j = 1; j <= m; ++j)
		{
			if (map[0][j] == 'F')
			{
				st = j;
				break;
			}
		}
		for (j = 1; j <= m; ++j)
		{
			if (map[n - 1][j] == 'G')
			{
				ed = j;
				break;
			}
		}
		
		memset(ans, 1, sizeof(ans));
		ans[0][0][st] = 0;
		queue.init(); 
		queue.add(0, 0, st);
		for (i = 1; i <= queue.tot; ++i)
		{
			int tx = queue.x[i];
			int ty = queue.y[i];
			int pr = ans[queue.t[i] % m][tx][ty] + 1;
			tt = queue.t[i] + 1;
			if (tt > totstep)
			{
				//break;
			}
			queue.go(tt, tx + 1, ty, pr);
			queue.go(tt, tx - 1, ty, pr);
			queue.go(tt, tx, ty - 1, pr);
			queue.go(tt, tx, ty + 1, pr);
			if (ans[tt % m][n - 1][ed] < 65536)
			{
				break;
			}
		}
		if (ans[tt % m][n - 1][ed] < 65536)
		{
			printf("The minimum number of turns is %d.\n", ans[tt % m][n - 1][ed]);
		}
		else
		{
			printf("The problem has no solution.\n");
		}
	}
	return 0;
}
