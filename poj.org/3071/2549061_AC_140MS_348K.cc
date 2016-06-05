#include <stdio.h>
#include <string.h>

const int MAXN = 128;

double win[MAXN][MAXN];
double wins[8][MAXN];

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i, j, k, m;
		m = 1 << n;
		memset(win, 0, sizeof(win));
		memset(wins, 0, sizeof(wins));
		for (i = 0; i < m; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				scanf("%lf", &win[i][j]);
			}
			wins[0][i] = win[i][i ^ 1];
		}
		
		for (i = 1; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				int st = ((j >> i) ^ 1) << i;
				int ed = st + (1 << i);
				for (k = st; k < ed; ++k)
				{
					wins[i][j] += wins[i - 1][k] * win[j][k]; 
				}
				wins[i][j] *= wins[i - 1][j];
			}
		}
		int ans = 0;
		for (i = 1; i < m; ++i)
		{
			if (wins[n - 1][i] > wins[n - 1][ans])
			{
				ans = i;
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}
