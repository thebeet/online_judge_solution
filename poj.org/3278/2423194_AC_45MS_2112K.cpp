#include <stdio.h>
#include <memory.h>

#define MAXN 300000

int gone[300010];
int dl[300010];

int main()
{
	int n, k, tar, dend;
	
	while(scanf("%d%d", &n, &k) != EOF)
	{
		if (n >= k)
		{
			printf("%d\n", n - k);
			continue;
		} 
		memset(gone, 0, sizeof(gone));
		gone[n] = 1;
		dl[0] = 0;
		dl[1] = n;
		dend = 1;
		while (gone[k] == 0)
		{
			tar = dl[++dl[0]];
			if (((tar - 1) > 0) && (gone[tar - 1] == 0))
			{
				gone[tar - 1] = gone[tar] + 1;
				dl[++dend] = tar - 1;
			}
			if (((tar + 1) <= MAXN) && (gone[tar + 1] == 0))
			{
				gone[tar + 1] = gone[tar] + 1;
				dl[++dend] = tar + 1;
			}
			if (((tar << 1) <= MAXN) && (gone[tar << 1] == 0))
			{
				gone[tar << 1] = gone[tar] + 1;
				dl[++dend] = tar << 1;
			}
		}
		printf("%d\n", gone[k] - 1);
	}
	return 0;
}
