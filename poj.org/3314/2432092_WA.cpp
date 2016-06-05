#include <stdio.h>
#include <memory.h>

char box[200][20];
char newitem[200][20];

int main()
{
	int n, w, b;
	while (scanf("%d%d%d", &n, &w, &b), n > 0)
	{
		int i;
		int ans[1010];
		int height;
		int pr_height;
		memset(box, '.', sizeof(box));
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		ans[1] = 0;
		height = 0;
		
		for (i = 1; i <= n; ++i)
		{
			int j, k, m;
			scanf("%d", &m);
			memset(newitem, '.', sizeof(newitem));

			for (j = m; j >= 1; --j)
			{
				scanf("%s", newitem[j] + 1);
			}
			
			while (true)
			{
				for (k = 1; k <= w; ++k)
				{
					if (newitem[m][k] == 'X')
					{
						break;
					}
				}
				if (k <= w)
				{
					break;
				}
				--m;
				if (m == 0) break;
			}
			if (m == 0) continue;
			j = 1;
			while (true)
			{
				for (k = 1; k <= w; ++k)
				{
					if (newitem[j][k] == 'X')
					{
						break;
					}
				}
				if (k <= w)
				{
					break;
				}
				++j;
			}
			if (j != 1)
			{
				for (k = j; k <= m; ++k)
				{
					memcpy(newitem[k - j + 1], newitem[k], sizeof(newitem[k]));
				}
			}
			m -= (j - 1);
					
			pr_height = height;
			while (true)
			{
				if (height == 0)
				{
					break;
				}
				for (j = 1; j <= m; ++j)
				{
					for (k = 1; k <= w; ++k)
					{
						if ((newitem[j][k] == 'X') && (box[height + j - 1][k] == 'X'))
						{
							 break;
						}
					}
					if (k <= w)
					{
						break;
					}
				}
				if (j <= m)
				{
					if (height + m > b)
					{
						ans[++ans[0]] = m;
						pr_height = 0;
						height = 0;
						memset(box, '.', sizeof(box));
					}
					else
					{
						ans[ans[0]] = height + m;
					}
					break;
				}
				height--;
			}
			
			for (j = 1; j <= m; ++j)
			{
				for (k = 1; k <= w; ++k)
				{
					if (newitem[j][k] == 'X')
					{
						box[height + j][k] = newitem[j][k];
					}
				}
			}
			height += m;
			if (height < pr_height)
			{
				height = pr_height;
				ans[ans[0]] = height;
			}
		}
		for (i = 1; i < ans[0]; ++i)
		{
			printf("%d ", ans[i]);
		}
		printf("%d\n", ans[ans[0]]);
	}
	return 0;
}
