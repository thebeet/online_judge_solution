#include <stdio.h>

struct t_ans
{
	int x, y;
}ans[3800500];

int n;
int tot;

void makeans(int n0, int m0, int n1, int m1)
{
	int m2 = m0 + m1;
	if (m2 > n)
	{
		return;
	}
	int n2 = n0 + n1;
	makeans(n0, m0, n2, m2);
	ans[++tot].x = n2;
	ans[tot].y = m2;
	makeans(n2, m2, n1, m1);
}

int main()
{
	int i, c, m;
	scanf("%d%d", &n, &c);
	makeans(0, 1, 1, 2);
	ans[0].x = 0;
	ans[0].y = 1;
	if (n == 1)
	{
		for (i = 1; i <= c; ++i)
		{
			scanf("%d", &m);
			if (m == 1)
			{
				printf("0/1\n");
			}
			else if (m == 2)
			{
				printf("1/1\n");
			}
			else
			{
				printf("No Solution\n");
			}
		}
	}
	else
	{		
		ans[++tot].x = 1;
		ans[tot].y = 2;
		for (i = 1; i <= c; ++i)
		{
			scanf("%d", &m);
			--m;
			if (m <= tot)
			{
				printf("%d/%d\n", ans[m].x, ans[m].y);
			}
			else if (m <= tot + tot)
			{
				m = tot + tot - m;
				printf("%d/%d\n", ans[m].y - ans[m].x, ans[m].y);
			}
			else
			{
				printf("No Solution\n");
			}
		}
	}
	return 0;
}
