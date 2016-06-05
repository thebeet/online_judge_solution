#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct cake
{
	int w;
	int d;
}cakes[1010];

bool cmp(cake c1, cake c2)
{
	return (c1.w * c1.d < c2.w * c2.d);
}

int main()
{
	int n, w, d;
	while (scanf("%d%d%d", &n, &w, &d), (n + w + d) > 0)
	{
		int pi, si;
		bool towardw;
		cakes[1].w = w;
		cakes[1].d = d;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d%d", &pi, &si);
			towardw = false;
			for (;;)
			{
				if (si < cakes[pi].w)
				{
					break;
				}
				towardw = true;
				si -= cakes[pi].w;
				if (si < cakes[pi].d)
				{
					break;
				}
				towardw = false;
				si -= cakes[pi].d;
			}
			if (towardw)
			{
				if (si + si > cakes[pi].d)
				{
					si = cakes[pi].d - si;
				}
				cakes[i + 1].d = si;
				cakes[i + 2].d = cakes[pi].d - si;
				cakes[i + 1].w = cakes[pi].w;
				cakes[i + 2].w = cakes[pi].w;
			}
			else
			{
				if (si + si > cakes[pi].w)
				{
					si = cakes[pi].w - si;
				}
				cakes[i + 1].w = si;
				cakes[i + 2].w = cakes[pi].w - si;
				cakes[i + 1].d = cakes[pi].d;
				cakes[i + 2].d = cakes[pi ].d;
			}
			memmove(&cakes[pi], (&cakes[pi + 1]), sizeof(cake) * (i - pi + 2));
		}
		
		sort(cakes + 1, cakes + 2 + n, cmp);
		
		for (int i = 1; i <= n; ++i)
		{
			printf("%d ", cakes[i].w * cakes[i].d);
		} 
		printf("%d\n", cakes[n + 1].w * cakes[n + 1].d);
	}
}
