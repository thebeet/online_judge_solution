#include <stdio.h>
#include <memory.h>

int hprimes[250010];
int semiprimes[250010];

int main()
{
	int i, j, n;
	memset(hprimes, 0, sizeof(hprimes));
	memset(semiprimes, 0, sizeof(semiprimes));
	
	for (i = 1; i <= 2000; ++i)
	{
		if (hprimes[i] == 0)
		{
			j = ((i * i) << 2) + (i << 1);
			while (j <= 250000)
			{
				hprimes[j] = 1;
				j += ((i << 2) + 1);
			}
			hprimes[++hprimes[0]] = i;
		}
	}
	for (i = 2001; i <= 250000; ++i)
	{
		if (hprimes[i] == 0)
		{
			hprimes[++hprimes[0]] = i;
		}
	}
	
	for (i = 1; i <= hprimes[0]; ++i)
	{
		if ((((hprimes[i] * hprimes[i]) << 2) + hprimes[i] + hprimes[i]) > 250000)
		{
			break;
		}
		for (j = i; j <= hprimes[0]; ++j)
		{
			int ret = ((hprimes[i] * hprimes[j]) << 2) + hprimes[i] + hprimes[j];
			if (ret > 250000)
			{
				break;
			}
			++semiprimes[ret];
		}
	}
	
	for (i = 1; i <= 250000; ++i)
	{
		if (semiprimes[i] > 1)
		{
			semiprimes[i] = 1;
		}
		semiprimes[i] += semiprimes[i - 1];
	}

	while (scanf("%d", &n), n > 0)
	{
		printf("%d %d\n", n, semiprimes[n/4]);
	}
	return 0;
}
