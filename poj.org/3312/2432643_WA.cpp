#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int namelength[1010];

int main()
{
	int ti = 0;
	int n, k;
	while (scanf("%d%d", &n, &k), n > 0)
	{
		int i, j, avg;
		char inp[200];
		memset(namelength, 0, sizeof(namelength));
		++ti; 
		
		if (ti != 1)
		{
			printf("\n");
		}
		printf("Case %d:", ti);
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", inp);
			namelength[i] = strlen(inp);
		}
		
		sort(namelength + 1, namelength + 1 + n);
		
		for (i = 1; i <= n; i += k)
		{
			avg = 0;
			for (j = 1; j <= k; ++j)
			{
				avg += namelength[j];
			}
			for (j = 1; j <= k; ++j)
			{
				if (((namelength[j] - 2) * k > avg) || ((namelength[j] + 2) * k < avg))
				{
					break;
				}
			}
			if (j <= k)
			{
				break;
			}
		}
		if (i <= n)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
