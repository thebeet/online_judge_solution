#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main()
{
	int n, s, mn, mx, m;
	while (scanf("%d", &n), n > 0)
	{
		s = 0;
		mn = 10000;
		mx = -1;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &m);
			mn = MIN(mn, m);
			mx = MAX(mx, m);
			s += m;
		}
		s -= mn + mx;
		printf("%d\n", s / (n - 2));
	}
	return 0;
}
