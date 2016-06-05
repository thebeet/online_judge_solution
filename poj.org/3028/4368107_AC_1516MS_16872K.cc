/*
 * PKU3028::Shoot_out.cpp
 *
 *  Created on: Nov 12, 2008 1:00:29 PM
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

using namespace std;

const int MAXN = 14;

double p[16];

double ans[16][1 << (MAXN - 1)][16];
bool ansed[1 << (MAXN - 1)];
int n;

const double esp = 1e-10;

int dblcmp(const double d)
{
	if (d > esp) return 1;
	if (d < -esp) return -1;
	return 0;
}

int shooters(const int people, int pps[16])
{
	int tn(0);
	for (int i = 0; i < n; ++i)
	{
		if (people & (1 << i))
		{
			pps[tn++] = i;
		}
	}
	return tn;
}

void calc(const int people)
{
	if (ansed[people] == false)
	{
		int ss[16];
		int nn;
		if ((nn = shooters(people, ss)) == 1)
		{
			ans[ss[0]][people][ss[0]] = 1.0;
		}
		else
		{
			for (int i = 0; i < nn; ++i)
			{
				int restpeople = people ^ (1 << ss[i]);
				calc(restpeople);
			}
			double ps[16][16];
			memset(ps, 0, sizeof(ps));
			for (int i = 0; i < nn; ++i)
			{
				int r(0);
				ps[i][ss[i]] = -1.0;
				for (int j = 0; j < nn; ++j)
				{
					if (i == j) continue;
					int next = (i + 1) % nn;
					if (next == j)
					{
						(++next) %= nn;
					}
					int restpeople = people ^ (1 << ss[j]);
					int ret = dblcmp(ps[i][ss[i]] - ans[ss[next]][restpeople][ss[i]]);
					if (ret == 0)
					{
						for (int k = 0; k < n; ++k)
						{
							ps[i][k] = (ps[i][k] * r + ans[ss[next]][restpeople][k]) / (double)(r + 1);
						}
						++r;
					}
					else if (ret == -1)
					{
//						memcpy(ps[i], ans[next][restpeople], sizeof(double) * 16);
						for (int k = 0; k < n; ++k)
						{
							ps[i][k] = ans[ss[next]][restpeople][k];
						}
						r = 1;
					}
				}
			}
			for (int i = 0; i < nn; ++i)
			{
				for (int j = 0; j < nn; ++j)
				{
					ans[ss[i]][people][ss[j]] = 0.0;
					double dpp(1.0);
					for (int k = i; ; )
					{
						ans[ss[i]][people][ss[j]] += ps[k][ss[j]] * dpp * p[ss[k]];
						dpp *= (1 - p[ss[k]]);
						(++k) %= nn;
						if (k == i) break;
					}
					dpp = 1 - dpp;
					ans[ss[i]][people][ss[j]] /= dpp;
				}
			}
		}
		ansed[people] = true;
	}
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &p[i]);
			p[i] /= 100.0;
		}
		memset(ans, 0, sizeof(ans));
		memset(ansed, false, sizeof(ansed));
		calc((1 << n) - 1);
		for (int i = 0; i < n; ++i)
		{
			printf("%.2lf ", ans[0][(1 << n) - 1][i] * 100.0);
		}
		printf("\n");
	}
	return 0;
}


