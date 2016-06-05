#include <stdio.h>
#include <string.h>

int wpri[10240];
int pri[10485760];

int find_min(void)
{
	int i;
	for (i = 0; i < 10240; ++i)
	{
		if (wpri[i] > 0)
		{
			break;
		}
	}
	if (i == 10240)
	{
		return 0;
	}
	for (int j = 0; j < 1024; ++j)
	{
		int p = (i << 10) + j;
		if (pri[p] > 0)
		{
			int ret = pri[p];
			pri[p] = 0;
			--wpri[i];
			return ret;
		}
	}
}

int find_max(void)
{
	int i;
	for (i = 10240 - 1; i >= 0; --i)
	{
		if (wpri[i] > 0)
		{
			break;
		}
	}
	if (i == -1)
	{
		return 0;
	}
	for (int j = 1024 - 1; j >= 0; --j)
	{
		int p = (i << 10) + j;
		if (pri[p] > 0)
		{
			int ret = pri[p];
			pri[p] = 0;
			--wpri[i];
			return ret;
		}
	}
}

int main()
{
	int op;
	while (scanf("%d", &op), (op != 0))
	{
		if (op == 1)
		{
			int id, pr;
			scanf("%d%d", &id, &pr);
			pri[pr] = id;
			++wpri[pr >> 10];
		}
		else if (op == 2)
		{
			printf("%d\n", find_max());
		}
		else if (op == 3)
		{
			printf("%d\n", find_min());
		}
	}
	return 0;
}
