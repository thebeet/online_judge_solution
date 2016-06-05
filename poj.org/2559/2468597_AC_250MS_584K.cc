#include <stdio.h>

#define MAXN 100010
#define INT long long
#define fmt "%I64d"

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

INT stack[MAXN];
INT deepth[MAXN];

int main()
{
	INT n;
	while (scanf(fmt, &n), n > 0)
	{
		INT i, m, ans;
		ans = 0;
		for (i = 1; i <= n; ++i)
		{
			scanf(fmt, &m);
			deepth[stack[0] + 1] = 0;
			for (; (stack[0] > 0) && (stack[stack[0]] > m); )
			{
				deepth[stack[0]] += deepth[stack[0] + 1];
				ans = MAX(ans, deepth[stack[0]] * stack[stack[0]]);
//				printf("deepth = %lld, stack = %lld\n", deepth[stack[0]], stack[stack[0]]);
				--stack[0];
			}
			stack[++stack[0]] = m;
			deepth[stack[0]] += 1;
		}
			deepth[stack[0] + 1] = 0;
		while (stack[0] > 0)
		{
			deepth[stack[0]] += deepth[stack[0] + 1];
			ans = MAX(ans, deepth[stack[0]] * stack[stack[0]]);
//			printf("deepth = %lld, stack = %lld\n", deepth[stack[0]], stack[stack[0]]);
			--stack[0];
		}
		printf(fmt"\n", ans);
	}
	return 0;
}

