#include <stdio.h>

int main()
{
	int f0, f1, f2;
	while (scanf("%d%d%d", &f0, &f1, &f2) != EOF)
	{
		printf("%d %d %d\n", f2 * 3 - f1 * 3 + f0, f2 * 6 - f1 * 8 + f0 * 3, f2 * 10 - f1 * 15 + f0 * 6);
	}
	return 0;
}
