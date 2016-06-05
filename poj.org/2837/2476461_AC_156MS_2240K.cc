#include <stdio.h>

int ans[1024][1024];

void paint(int h, int d, int x, int y, int u)
{
	if (h == 0)
	{
		ans[x][y] = d + u;
	}
	else
	{
		paint(h - 1, d, x, y, u);
		paint(h - 1, d + (1 << h), x + (1 << (h - 1)), y, 1);
		paint(h - 1, d + (1 << h), x, y + (1 << (h - 1)), 0);
		paint(h - 1, d, x + (1 << (h - 1)), y + (1 << (h - 1)), u);
	}
}

int main()
{
	int k;
	scanf("%d", &k);
	paint(k, 0, 0, 0, 1);
	for (int i = 0; i < (1 << k); ++i)
	{
		int j;
		for (j = 0; j < (1 << k) - 1; ++j)
		{
			printf("%d ", ans[i][j]);
		}
		printf("%d\n", ans[i][j]);
	}
	return 0;
}
