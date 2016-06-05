#include <stdio.h>
#include <string.h>

char queue[32][16];
char ans[32][16];
char tmp[16];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m;
		scanf("%d%d", &n, &m);
		memset(queue, 0, sizeof(queue));
		memset(ans, 0, sizeof(ans));
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", queue[i]);
		}
		for (i = 1; i <= m; ++i)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			memcpy(ans[t], queue[f], 16);
			queue[f][0] = '\0';
		}
		int k = 0;
		for (i = 1; i <= n; ++i)
		{
			if (ans[i][0] != '\0')
			{
				printf("%s%c", ans[i], (i == n) ? '\n' : ' ');
			}
			else
			{
				while (queue[++k][0] == '\0')
				{
				}
				printf("%s%c", queue[k], (i == n) ? '\n' : ' ');
			}
		}
	}
	return 0;
}
