#include <stdio.h>
#include <string.h>

int map[128][128];
int n;

int hlo, hhi;
bool gone[128][128];
int queuex[16384];
int queuey[16384];

void go(int x, int y)
{
	if ((gone[x][y] == false) && (map[x][y] >= hlo) && (map[x][y] <= hhi))
	{
		queuex[++queuex[0]] = x;
		queuey[queuex[0]] = y;
		gone[x][y] = true;
	}
}

bool bfs(void)
{
	int i;
	if ((map[1][1] < hlo) || (map[1][1] > hhi))
	{
		return false;
	}
	memset(gone, false, sizeof(gone));
	queuex[0] = 1;
	queuex[1] = queuey[1] = 1;
	gone[1][1] = true;
	for (i = 1; i <= queuex[0]; ++i)
	{
		go(queuex[i] + 1, queuey[i]);
		go(queuex[i] - 1, queuey[i]);
		go(queuex[i], queuey[i] + 1);
		go(queuex[i], queuey[i] - 1);
	}
	return gone[n][n];
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <=tn; ++ti)
	{
		int i, j;
		memset(map, 1, sizeof(map));
		
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				scanf("%d", &map[i][j]);
			}
		}
		
		int lo = -1;
		int hi = 200;
		while (lo + 1 < hi)
		{
			int mid = (lo + hi) >> 1;
			for (hlo = 0, hhi = mid; hhi <= 200; ++hlo, ++hhi)
			{
				if (bfs())
				{
					break;
				}
			}
			if (hhi <= 200)
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		printf("Scenario #%d:\n", ti);
		printf("%d\n\n", hi);
	}
	return 0;
}
