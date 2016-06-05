#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int main()
{
	int i, j, f, r;
	int ff[20], rr[20];
	int vn;
	double v[400];
	double ans;
	
	while (scanf("%d", &f), f > 0)
	{
		memset(ff, 0, sizeof(ff));
		memset(rr, 0, sizeof(rr));
		memset(v, 0, sizeof(v));
		vn = 0;
		
		scanf("%d", &r);
		for (i = 1; i <= f; ++i)
		{
			scanf("%d", &ff[i]);
		}
		for (i = 1; i <= r; ++i)
		{
			scanf("%d", &rr[i]);
		}
		for (i = 1; i <= f; ++i)
		{
			for (j = 1; j <= r; ++j)
			{
				++vn;
				v[vn] = (double)ff[i] / rr[j];
			}
		}
		ans = 1;
		sort(v + 1, v + 1 + vn);
		for (i = 2; i <= vn; ++i)
		{
			if (ans < v[i] / v[i - 1]) ans = v[i] / v[i - 1];
		}
		printf("%.2f\n", ans);
	}
	return 0;
}
				
		