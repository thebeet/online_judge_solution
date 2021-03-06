#include <iostream>
#include <algorithm>

using namespace std;

int tri[9]=
{7,152,52,352,34304,71680,155648,3200,12544};
int tris[9][3]=
{
		{0, 1, 2},
		{3, 4, 7},
		{2, 4, 5},
		{5, 6, 8},
		{9, 10, 15},
		{11, 12, 16},
		{13, 14, 17},
		{7, 10, 11},
		{8, 12, 13}
};
int reltri[18][3];
int tran[11][11];

char stat_score[1 << 18];

void Init()
{
	memset(reltri, 0, sizeof(reltri));
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			reltri[tris[i][j]][++reltri[tris[i][j]][0]] = i;
		}
	}
	tran[1][2] = 0;
	tran[1][3] = 1;
	tran[2][3] = 2;
	tran[2][4] = 3;
	tran[2][5] = 4;
	tran[3][5] = 5;
	tran[3][6] = 6;
	tran[4][5] = 7;
	tran[5][6] = 8;
	tran[4][7] = 9;
	tran[4][8] = 10;
	tran[5][8] = 11;
	tran[5][9] = 12;
	tran[6][9] = 13;
	tran[6][10] = 14;
	tran[7][8] = 15;
	tran[8][9] = 16;
	tran[9][10] = 17;
}

int Stat_Change(int &stat, const int move)
{
	int newstat = stat | (1 << move);
	int ret(0);
	for (int i = 1; i <= reltri[move][0]; ++i)
	{
		int t = reltri[move][i];
		if (((newstat & tri[t]) == tri[t]) && ((stat & tri[t]) != tri[t]))
		{
			++ret;
		}
	}
	stat = newstat;
	return ret;
}

int calc_score(const int stat)
{
	if (stat_score[stat] == 0)
	{
		int a(0);
		int r(0);
		for (int i = 0; i < 9; ++i)
		{
			if ((stat & tri[i]) != tri[i])
			{
				++r;
			}
		}
		for (int i = 0; i < 18; ++i)
		{
			if ((stat & (1 << i)) == 0)
			{
				int newstat(stat);
				int ret = Stat_Change(newstat, i);
				if (ret > 0)
				{
					a = max(a, calc_score(newstat) + ret);
				}
				else
				{
					a = max(a, r - calc_score(newstat));
				}
				if ((a >= 5) || (a == r)) break;
			}
		}
		stat_score[stat] = a;
	}
	return stat_score[stat];
}

int main()
{
	int tn;
	Init();
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
			int ret = Stat_Change(st, tran[a][b]);
			if (ret > 0)
			{
				score[p] += ret;
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
