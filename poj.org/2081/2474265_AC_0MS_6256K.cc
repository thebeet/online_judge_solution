#include <stdio.h>
#include <string.h>

int ans[500010];
bool hash[4194304];

int main()
{
	memset(ans, 0, sizeof(ans));
	memset(hash, false, sizeof(hash));
	for (int i = 1; i <= 500000; ++i)
	{
		if ((ans[i - 1] - i > 0) && (hash[ans[i - 1] - i] == false))
		{
			ans[i] = ans[i - 1] - i;
			hash[ans[i]] = true;
		}
		else
		{
			ans[i] = ans[i - 1] + i;
			hash[ans[i]] = true;
		}
	}
	int n;
	while (scanf("%d", &n), n >= 0)
	{
		printf("%d\n", ans[n]);
	}
	return 0;
}
