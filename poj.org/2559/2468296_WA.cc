#include <stdio.h>

#define MAXN 100010

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int stack[MAXN];
int deepth[MAXN];

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		int i, m, w, ans;
		ans = 0;
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			for (w = 1; (stack[0] > 0) && (stack[stack[0]] > m); ++w)
			{
				ans = MAX(ans, deepth[stack[0]] * stack[stack[0]]);
				--stack[0];
				deepth[stack[0]] = MAX(deepth[stack[0]], deepth[stack[0] + 1] + 1);
			}
			stack[++stack[0]] = m;
			deepth[stack[0]] = 1;
			ans = MAX(ans, w * m);
		}
		for (i = 1; i <= stack[0]; ++i)
		{
			ans = MAX(ans, stack[i] * deepth[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

