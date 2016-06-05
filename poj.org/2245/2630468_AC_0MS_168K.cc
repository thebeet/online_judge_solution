#include <stdio.h>

int n;
int inp[16];
int out[16];

void dfs(int p, int st)
{
	if (p > 6)
	{
		int i;
		for (i = 1; i <= 6; ++i)
		{
			printf("%d%c", out[i], ((i == 6) ? '\n' : ' '));
		}
	}
	else
	{
		for ( ; st <= n; )
		{
			out[p] = inp[st];
			dfs(p + 1, ++st);
		}
	}
}

int main()
{
	int ti = 0;
	while (scanf("%d", &n), n > 0)
	{
		if (++ti > 1)
		{
			printf("\n");
		}
		int i;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &inp[i]);
		}
		dfs(1, 1);
	}
	return 0;
}
