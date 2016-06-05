#include <iostream>
#include <algorithm>

using namespace std;

struct stone
{
	int weight, cost;
}stones[16];

int perm[16];

int main()
{
	int i, n, d;
	cin >> n >> d;
	for (i = 0; i < n; ++i)
	{
		cin >> stones[i].weight >> stones[i].cost;
		perm[i] = i;
	}
	int ans = 0;
	for (;;)
	{
		int w[2] = {0, 0};
		int s = 0;
		int pt = 0;
		for (i = 0; i < n; ++i)
		{
			if (pt == 1)
			{
				s += stones[perm[i]].cost;
			}
			w[pt] += stones[perm[i]].weight;
			if (w[pt] - d > w[pt ^ 1])
			{
				pt ^= 1;
			}
		}
		ans = max(ans, s);
		if (next_permutation(perm, perm + n) == false)
		{
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
