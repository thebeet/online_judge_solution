#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct planet
{
	int id, x, y, z;
}planets[1024];

int edge[1024][1024];
int deg[1024];

int queue[1024];
int s[1024];

int dis(const planet &p1, const planet &p2)
{
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	int dz = p1.z - p2.z;
	return (dx * dx + dy * dy + dz * dz);
}

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i, j, mn, pm;
		memset(planets, 0, sizeof(planets));
		memset(edge, 0, sizeof(edge));
		
		scanf("%d%d%d%d", &planets[1].id, &planets[1].x, &planets[1].y, &planets[1].z);
		for (i = 2; i <= n; ++i)
		{
			scanf("%d%d%d%d", &planets[i].id, &planets[i].x, &planets[i].y, &planets[i].z);
			mn = dis(planets[1], planets[i]);
			pm = 1;
			for (j = 1; j < i; ++j)
			{
				int ds = dis(planets[j], planets[i]);
				if (mn > ds)
				{
					mn = ds;
					pm = j;
				}
			}
			edge[pm][++edge[pm][0]] = i;
			edge[i][++edge[i][0]] = pm;
		}
		
		memset(queue, 0, sizeof(queue));
		memset(s, 0, sizeof(s));
		memset(deg, 0, sizeof(deg));
		
		for (i = 1; i <= n; ++i)
		{
			deg[i] = edge[i][0];
			if (edge[i][0] == 1)
			{
				queue[++queue[0]] = i;
				s[queue[0]] = 1;
			}
		}
		
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= edge[queue[i]][0]; ++j)
			{
				--deg[edge[queue[i]][j]];
				if (deg[edge[queue[i]][j]] == 1)
				{
					queue[++queue[0]] = edge[queue[i]][j];
					s[queue[0]] = s[i] + 1;
				}
			}
		}
		if (n == 1)
		{
			printf("%d\n", planets[i].id);
		}
		else
		{
			if (s[n] == s[n - 1])
			{
				printf("%d %d\n", min(planets[queue[n]].id, planets[queue[n - 1]].id), max(planets[queue[n]].id, planets[queue[n - 1]].id));
			}
			else
			{
				printf("%d\n", planets[queue[n]].id);
			}
		}
	}
	
}
