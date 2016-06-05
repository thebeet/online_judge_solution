#include <stdio.h>
#include <algorithm>

using namespace std;

struct cow
{
	int w, s;
}cows[65536];

int s[65536];

bool cmp(const cow &cow1, const cow &cow2)
{
	return (cow1.w + cow1.s < cow2.w + cow2.s);
}

int main()
{
	int i, n;
	scanf("%d", &n);
	memset(s, 0, sizeof(s));
	for (i = 1; i <= n; ++i)
	{
		scanf("%d%d", &cows[i].w, &cows[i].s);
	}
	sort(cows + 1, cows + 1 + n, cmp);
	
	for (i = 1; i <= n; ++i)
	{
		s[i] = s[i - 1] + cows[i - 1].w;
	}
	int ans = -cows[i].s;
	for (i = 1; i <= n; ++i)
	{
		if (ans < (s[i] - cows[i].s))
		{
			ans = s[i] - cows[i].s;
		}
	}
	printf("%d\n", ans);
	return 0;
}
