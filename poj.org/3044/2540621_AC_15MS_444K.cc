#include <stdio.h>
#include <string.h>

const int MAXN = 65536;

int stack[MAXN];

int main()
{
	int i, n, w, ans;
	memset(stack, 0, sizeof(stack));
	ans = 0;
	
	scanf("%d%d", &n, &w);
	for (i = 1; i <= n; ++i)
	{
		int y;
		scanf("%*d%d", &y);
		while (stack[stack[0]] > y)
		{
			++ans;
			--stack[0];
		}
		if (stack[stack[0]] < y)
		{
			stack[++stack[0]] = y;
		}
	}
	ans += stack[0];
	printf("%d\n", ans);
	return 0;
}
