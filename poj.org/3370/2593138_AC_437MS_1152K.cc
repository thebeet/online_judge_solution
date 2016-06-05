#include <cstdio>
#include <cstring>

int tmod[100010];
char buf[1000100];

int main()
{
	int c, n;
	while ((scanf("%d%d", &c, &n) != EOF) && (c > 0))
	{
		int i, j, m;
		int sum = 0;
		memset(tmod, 10, sizeof(tmod));
		tmod[0] = 0;
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			sum = (sum + m) % c;
			if (tmod[sum] < n)
			{
				for (j = tmod[sum] + 1; j < i; ++j)
				{
					printf("%d ", j);
				}
				printf("%d\n", i);
				break;
			}
			tmod[sum] = i;
		}
		gets(buf);
	}
	return 0;
}
