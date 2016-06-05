#include <stdio.h>
#include <memory.h>

#define INT long long
#define MAXN 100010
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

INT dis[MAXN];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		INT i, k, m, n, lo, hi, mid, total, sig;
		memset(dis, 0, sizeof(dis));
		lo = 0;
		hi = 0;
		
		scanf("%lld", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%lld", &dis[i]);
			hi = MAX(hi, dis[i]);
		}
		scanf("%lld%lld", &m, &k); 
		
		if (k == 1)
		{
			printf("%lld\n", hi);
		}
		else
		{
			for (; mid = (lo + hi) / 2, lo + 1 < hi;)
			{
				total = 0;
				for (i = 1; i <= n; ++i)
				{
					if (dis[i] > mid)
					{
					 	if (((dis[i] + k - 1) / k) > mid)
					 	{
					 		break;
					 	}
					 	else
					 	{
					 		sig = (dis[i] - mid + k - 2) / (k - 1);
					 		if (sig > mid)
					 		{
					 			break;
					 		}
					 		total += sig;
						 	if (total > m * mid) break;
					 	}
					}
				}
				if (i > n)
				{
					hi = mid;
				}
				else
				{
					lo = mid;
				}
			}
			printf("%lld\n", hi);
		}
	}
	return 0;
}
