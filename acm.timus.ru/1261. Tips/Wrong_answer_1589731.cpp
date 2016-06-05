#include <stdio.h>
#include <memory.h>

long fz[100];

int main()
{
	long i, n ,m;
	scanf("%ld", &n);
	m = n + 1;
	memset(fz, 0, sizeof(fz));
	while (m > 0)
	{
		fz[0]++;
		fz[fz[0]] = m % 3;
		m /= 3;
	}
	for (i = 1; i <= fz[0]; i++)
	{
		if (fz[i] > 1)
		{
			fz[i] = 0;
			fz[i + 1]++;
		}
	}
	if (fz[fz[0] + 1] == 1) fz[0]++;
	m = 0;
	for (i = fz[0]; i>=1; i--)
	{
		m = m * 3 + fz[i];
	}
	printf("%ld %ld\n", m, m - n);
	return 0;
}
