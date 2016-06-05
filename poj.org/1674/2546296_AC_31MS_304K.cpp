#include <stdio.h>
#include <string.h>

int list[10010];
bool gone[10010];

int calc(int p)
{
	if (gone[p])
	{
		return 0;
	}
	gone[p] = true;
	return calc(list[p]) + 1;
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, sum;
		sum = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &list[i]);
		}
		memset(gone, false, n + 1);
		for (i = 1; i <= n; ++i)
		{
			if (gone[i] == false)
			{
				sum += calc(i) - 1;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
