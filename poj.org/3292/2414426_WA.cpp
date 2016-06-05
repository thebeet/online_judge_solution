#include <stdio.h>
#include <memory.h>

int hprimes[250001];

int main()
{
	int i, i4, j, n;
	memset(hprimes, 0, sizeof(hprimes));
	
	setbuf(stdout, NULL);
	
	for (i = 1; i <= 2000; ++i)
	{
		i4 = i << 2;
		j = (i4 + 2) * i;
		++i4;
		while (j <= 250000)
		{
			hprimes[j] += 1;
			j += i4;
		}
		if (hprimes[i] == 1)
		{
			hprimes[i] = hprimes[i - 1] + 1;
		}
		else 
		{
			hprimes[i] = hprimes[i - 1];
		}
	}
	for (i = 2001; i <= 250000; ++i)
	{
		if (hprimes[i] == 1)
		{
			hprimes[i] = hprimes[i - 1] + 1;
		}
		else
		{
			hprimes[i] = hprimes[i - 1];
		}
	}

	while (scanf("%d", &n), n > 0)
	{
		printf("%d %d\n", n, hprimes[n/4]);
	}
	return 0;
}
