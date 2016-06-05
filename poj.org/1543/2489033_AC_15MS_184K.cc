#include <stdio.h>

int main()
{
	int n, i, j, k, l, i3, j3, k3, l3;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		i3 = i * i * i;
		for (j = 2; j <= i; ++j)
		{
			j3 = j * j * j;
			for (k = j; k <= i; ++k)
			{
				k3 = k * k * k;
				for (l = k; l <= i; ++l)
				{
					l3 = l * l * l;
					if (i3 == j3 + k3 + l3)
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, l);
					}
				}
			}
		}
	}
	return 0;
}
