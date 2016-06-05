/*
 * Layout.cpp
 *
 *  Created on: 2008-10-14
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct Path
{
	int f, t;
	int len;
};

Path paths[20010];
int u[10010];

int main()
{
	int n, ml, md;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d%d", &ml, &md);
		for (int i = 0; i < ml; ++i)
		{
			scanf("%d%d%d", &paths[i].f, &paths[i].t, &paths[i].len);
		}
		md += ml;
		for (int i = ml; i < md; ++i)
		{
			scanf("%d%d%d", &paths[i].t, &paths[i].f, &paths[i].len);
			paths[i].len = -paths[i].len;
		}
		for (int i = 1; i <= n; ++i)
		{
			u[i] = 2000000100;
		}
		u[1] = 0;
		for (int k = 1; k < n; ++k)
		{
			bool flag = false;
			for (int j = md - 1; j >= 0; --j)
			{
				if ((u[paths[j].f] < 2000000000) &&
					(u[paths[j].t] > u[paths[j].f] + paths[j].len))
				{
					u[paths[j].t] = u[paths[j].f] + paths[j].len;
					if (u[paths[j].t] < 0)
					{
						flag = false;
						u[n] = -1;
						break;
					}
					flag = true;
				}
			}
			if (flag == false) break;
		}
		if (u[n] > 2000000000)
		{
			cout << -2 << endl;
		}
		else if (u[n] < 0)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << u[n] << endl;
		}
	}
	return 0;
}
