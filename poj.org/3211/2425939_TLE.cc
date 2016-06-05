#include <stdio.h>
#include <string.h>

char colors[20][20];
char inp[20];
int data[20][110];
int s[20];
int dp[1001010];

int main()
{
	int n, m, ts, tar;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		int i, j, k, nclo, ans;
		
		ans = 0;
		memset(colors, 0, sizeof(colors));
		memset(inp, 0, sizeof(inp));
		memset(data, 0, sizeof(data));
		memset(s, 0, sizeof(s));
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", colors[i]);
		}
		
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%s", &nclo, inp);
			for (j = 1; ; ++j)
			{
				if (strcmp(inp, colors[j]) == 0)
				{
					break;
				}
			}
			data[j][++data[j][0]] = nclo;
			s[j] += nclo;
		}
		
		for (j = 1; j <= n; ++j)
		{
			ts = 0;
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			
			for (k = 1; k <= data[j][0]; ++k)
			{
				tar = data[j][k];
				if (((ts + tar) << 1) > s[j])
				{
					ts = (s[j] >> 1) - tar;
				}
				for (i = ts; i >= 0; --i)
				{
					dp[i + tar] += dp[i];
				}
				ts += tar;
			}
			ts = nclo >> 1;
			while (dp[ts] == 0)
			{
				--ts;
			}
			ans += (s[j] - ts);
		}
		printf("%d\n", ans);
	}
	return 0;
}
