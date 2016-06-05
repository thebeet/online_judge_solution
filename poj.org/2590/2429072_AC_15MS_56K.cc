#include <stdio.h>

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int x, y, i, ans;
		scanf("%d%d", &x, &y);
		ans = 0;
		x = y - x;
		for (i = 1; x > 0; ++i)
		{
			if (x <= i)
			{
				++ans;
				break;
			}
			x -= (i + i);
			ans += 2;
		}
		printf("%d\n", ans);
	}
	return 0;
}
