#include <stdio.h>

int main()
{
	int t, n, m, h, l, h0, l0;
	while(scanf("%d", &t) && t != 0)
	{		
		h0 = l0 = h = l = 0;
		while (scanf("%d%d", &n, &m) && n != -1)
		{
			l += n;
			if (l > t)
			{
				if (n > l0)
				{
					l0 = n;
				}
				l = n;
				h = h0;
				h0 = h + m;
				continue;
			}
			if (l > l0)
			{
			    l0 = l;
			}
			if (m + h > h0)
			{
				h0 = h + m;
			}
		}
		printf("%d x %d\n", l0, h0);
	}
	return 0;
}  
			
			
			
			
			
