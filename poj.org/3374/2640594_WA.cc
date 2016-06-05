#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct t_ans
{
	int x, y;
}ans[8000935];

bool operator < (const t_ans &a1, const t_ans &a2)
{
	return ((a1.x * a2.y) < (a2.x * a1.y));
}

int tot;

bool enb[5010][5010];

int main()
{
	int i, j, n, m, c, ti, tj;
	scanf("%d%d", &n, &c);
	for (i = 1; i <= n; ++i)
	{
		for (j = i + 1; j <= n; ++j)
		{
			if (enb[i][j] == false)
			{
				ans[++tot].x = i;
				ans[tot].y = j;
				ti = i << 1;
				tj = j << 1;
				while (tj <= n)
				{
					enb[ti][tj] = true;
					ti += i;
					tj += j;
				}
			}
		}
	}
	sort(ans + 1, ans + tot + 1);
	cout << tot << endl;
	for (i = 1; i <= c; ++i)
	{
		scanf("%d", &m);
		--m;
		if (m == 0)
		{
			printf("0/1\n");
		}
		else if (m == tot + 1)
		{
			printf("1/1\n");
		}
		else if (m > tot + 1)
		{
			printf("No Solution\n");
		}
		else
		{
			printf("%d/%d\n", ans[m].x, ans[m].y);
		}
	}
	return 0;
}
