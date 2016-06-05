#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 300;

int score[128][512];
int sortscore[128][1024];
int mxscore[1024][3];
int allscore[512];
int n, m;

int minwin(int p)
{
	int i, s;
	s = 0;
	for (i = 0; i <= maxn; ++i)
	{
		s -= allscore[i] - score[p][i] - score[p][i];
		if (s < 0)
		{
			s = 0;
		}
	}
	return s;
}

int maxwin(int p)
{
	int i, j;
	i = 1;
	for (j = 1; j <= m; ++j)
	{
		mxscore[j][0] = (mxscore[j][1] == sortscore[p][j]) ? mxscore[j][2] : mxscore[j][1]; 
	}
	int ans = 0;
	i = 1;
	for (j = 1; j <= m; ++j)
	{
		while ((i <= m) && (sortscore[p][i] <= mxscore[j][0]))
		{
			++i;
		}
		if (i > m)
		{
			break;
		}
		++i;
		++ans;
	}
	return ans;
}

int main()
{
	int ti, tn;
	
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, k, s;
		
		memset(score, 0, sizeof(score));
		memset(allscore, 0, sizeof(allscore));
		memset(mxscore, 0, sizeof(mxscore));
		
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				scanf("%d", &s);
				++score[i][s];
				++allscore[s];
			}
			s = 0;
			for (k = 0; k <= maxn; ++k)
			{
				for (j = 1; j <= score[i][k]; ++j)
				{
					sortscore[i][++s] = k;
					if (mxscore[s][1] < k)
					{
						mxscore[s][2] = mxscore[s][1];
						mxscore[s][1] = k;
					}
					else if (mxscore[s][2] < k)
					{
						mxscore[s][2] = k;
					}
				}
			}
		}
		for (i = 1; i <= n; ++i)
		{
			printf("%d %d\n", minwin(i), maxwin(i));
		}
	}
	return 0;
}
