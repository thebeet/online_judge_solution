/*
 * Triangle_War.cpp
 *
 *  Created on: 2009-3-15
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

int tri[9]=
{7, 152, 52, 352, 34304, 71680, 155648, 3200, 12544};

int tran[11][11] =
{
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 2, 3, 4, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 7, 0, 9, 10, 0, 0},
		{0, 0, 0, 0, 0, 0, 8, 0, 11, 12, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14},
		{0, 0, 0, 0, 0, 0, 0, 0, 15, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

bool Stat_Change(int &stat, const int move)
{
	int newstat = stat + (1 << move);
	for (int i = 0; i < 9; ++i)
	{
		if (((newstat & tri[i]) == tri[i]) && ((stat & tri[i]) != tri[i]))
		{
			stat = newstat;
			return true;
		}
	}
	stat = newstat;
	return false;
}

signed char stat_score[1 << 18];

int calc_score(const int stat)
{
	if (stat_score[stat] == 100)
	{
		int a(-100);
		int r(0);
		for (int i = 0; i < 9; ++i)
		{
			if ((stat & tri[i]) == tri[i])
			{
				++r;
			}
		}
		for (int i = 0; i < 18; ++i)
		{
			if ((stat & (1 << i)) == 0)
			{
				int newstat(stat);
				if (Stat_Change(newstat, i))
				{
					a = max(a, calc_score(newstat) + 1);
				}
				else
				{
					a = max(a, r - calc_score(newstat));
				}
			}
		}
		stat_score[stat] = a;
	}
	return stat_score[stat];
}


int main()
{
	int tn;
	memset(stat_score, 100, sizeof(stat_score));
	stat_score[(1 << 18) - 1] = 0;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		int st(0);
		int p(0);
		int score[2];
		score[0] = 0;
		score[1] = 0;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (Stat_Change(st, tran[a][b]))
			{
				++score[p];
			}
			else
			{
				p ^= 1;
			}
		}
		printf("Game %d: %c wins.\n", ti, ((((score[p] + calc_score(st)) >= 5) ^ (p == 0)) ? 'B' : 'A'));
	}
	return 0;
}
