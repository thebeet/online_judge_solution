/*
 * PKU3687::Labeling_Balls.cpp
 *
 *  Created on: Aug 31, 2008 12:09:08 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>

using namespace std;

char balls[256][256];

int deg[256];

int ans[256];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 0; ti < tn; ++ti)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		memset(balls, 0, sizeof(balls));
		memset(deg, 0, sizeof(deg));
		bool flag(false);
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (balls[a][b] == 0)
			{
				++deg[a];
			}
			if ((balls[a][b] == 2) || (a == b))
			{
				flag = true;
			}
			balls[a][b] = 1;
			balls[b][a] = 2;
		}
		if (flag)
		{
			printf("-1\n");
		}
		else
		{
			int i;
			for (i = n; i >= 1; --i)
			{
				int j;
				for (j = n; j >= 1; --j)
				{
					if (deg[j] == 0)
					{
						break;
					}
				}
				if (j >= 1)
				{
					deg[j] = -1;
					for (int k = 1; k <= n; ++k)
					{
						if (balls[k][j] == 1)
						{
							--deg[k];
						}
					}
					ans[j] = i;
				}
				else
				{
					break;
				}
			}
			if (i >= 1)
			{
				printf("-1\n");
			}
			else
			{
				for (int i = 1; i <= n; ++i)
				{
					printf("%d ", ans[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
