#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

map<string, int> id;

int scores[10010];
char buf[1024];

int main()
{
	char ch;
	int i, n, m;
	int lmid;
	scanf("%d", &n);
	memset(scores, 0, sizeof(scores));
	
	while (scanf("%c", &ch), ch != '\n')
	{
	}
	for (i = 1; i <= n; ++i)
	{
		fgets(buf, 128, stdin);
		id[buf] = i;
		if (strcmp("Li Ming\n", buf) == 0)
		{
			lmid = i;
		}
	}
	scanf("%d", &m);
	while (scanf("%c", &ch), ch != '\n')
	{
	}
	for (i = 1; i <= m; ++i)
	{
		int j;
		for (j = 1; j <= n; ++j)
		{
			int s;
			scanf("%d ", &s);
			fgets(buf, 128, stdin);
			scores[id[buf]] += s;
		}
		
		int rank = 1;
		for (j = 1; j <= n; ++j)
		{
			if (scores[j] > scores[lmid])
			{
				++rank;
			}
		}
		printf("%d\n", rank);
	}
	return 0;
}
