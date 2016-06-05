#include <stdio.h>
#include <string.h>

int scores[128];
char buf[128];

int main()
{
	int i, n, m;
	scanf("%d", &n);
	scanf("%*c");
	for (i = 1; i <= n; ++i)
	{
		fgets(buf, 128, stdin);
	}
	scanf("%d", &m);
	scanf("%*c");
	for (i = 1; i <= m; ++i)
	{
		int j;
		int lmscore;
		memset(scores, 0, sizeof(scores));
		for (j = 1; j <= n; ++j)
		{
			int s;
			scanf("%d ", &s);
			fgets(buf, 128, stdin);
			if (strcmp("Li Ming\n", buf) == 0)
			{
				lmscore = s;
			}
			++scores[s];
		}
		
		int rank = 1;
		for (j = 100; j > lmscore; --j)
		{
			rank += scores[j];
		}
		printf("%d\n", rank);
	}
	return 0;
}
