#include <cstdio>
#include <algorithm>

using namespace std;

int num[1048576];
int num_s[1048576];

void sort_nth(int f, int t, int k)
{
	int mid = num_s[(f + t) >> 1];
	int i(f);
	int j(t);
	for ( ; ; )
	{
		while (num_s[i] < mid)
		{
			++i;
		}
		while (mid < num_s[j])
		{
			--j;
		}
		if (i <= j)
		{
			swap(num_s[i++], num_s[j--]);
		}
		if (i > j)
		{
			break;
		}
	}
	if ((i < t) && (k >= i)) sort_nth(i, t, k);
	if ((f < j) && (k <= j)) sort_nth(f, j, k);
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &num[i]);
	}
	int f, t, k;
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &f, &t, &k);
		--f;
		--t;
		--k;
		k += f;
		memcpy(num_s + f, num + f, sizeof(int) * (t - f + 1));
		sort_nth(f, t, k);
		printf("%d\n", num_s[k]);
	}
	return 0;
}
;
