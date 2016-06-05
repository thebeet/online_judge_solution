#include <stdio.h>

int main()
{
	int n;
	setbuf(stdout, NULL);
	while (scanf("%d", &n), n > 0)
	{
		int j, k, s, r;
		for (j = 0; (n & (1 << j)) == 0; ++j);
		k = 0;
		s = 0;
		r = 0;
		s += (1 << j);
		++j;
		for (; (n & (1 << j)) > 0; )
		{
			r += (1 << k);
			++k;
			s += (1 << j);
			++j;
		}
		printf("%d\n", n - s + r + (1 << j));
	}
	return 0;
}
