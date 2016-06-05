#include <stdio.h>

#define MAXN 100010
#define INT long long

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

INT stack[MAXN];
INT deepth[MAXN];

int main()
{
	INT n;
	while (scanf("%I64d", &n), n > 0)
	{
		INT i, m, w, ans;
		ans = 0;
		for (i = 1; i <= n; ++i)
		{
			scanf("%I64d", &m);
			for (w = 1; (stack[0] > 0) && (stack[stack[0]] > m); w = deepth[stack[0] + 1] + 1)
			{
				ans = MAX(ans, deepth[stack[0]] * stack[stack[0]]);
				--stack[0];
				deepth[stack[0]] = MAX(deepth[stack[0]], deepth[stack[0] + 1] + 1);
			}
			stack[++stack[0]] = m;
			deepth[stack[0]] = w;
		}
		while (stack[0] > 0)
		{
			ans = MAX(ans, deepth[stack[0]] * stack[stack[0]]);
			--stack[0];
			deepth[stack[0]] = MAX(deepth[stack[0]], deepth[stack[0] + 1] + 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}

