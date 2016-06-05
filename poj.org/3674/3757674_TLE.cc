#include <iostream>
#include <algorithm>

using namespace std;

int skill[16][512];
int p[16];

int calc(int h, int p[], int enh)
{
	if (h < 4)
	{
		++h;
		int m(6 - h);
		int ans(0);
		for (int i = 0; i <= 10; ++i)
		{
			for (int j = p[i]; j >= p[i] - m; --j)
			{
				if (j > 0)
				{
					int t = skill[i][j];
					for (int k = j; k < p[i]; ++k)
					{
						skill[i][k] = skill[i][k + 1];
					}
					skill[i][p[i]] = t;
					int nowdam = skill[i][p[i]] * (10 + enh);
					--p[i];
					nowdam += calc(h, p, i);
					ans = max(ans, nowdam);
					++p[i];
					t = skill[i][p[i]];
					for (int k = p[i]; k > j; --k)
					{
						skill[i][k] = skill[i][k - 1];
					}
					skill[i][j] = t;
				}
			}
		}
		return ans;
	}
	if (h == 6) return 0;
	++h;
	int ans(0);
	for (int i = 0; i <= 10; ++i)
	{
		if (p[i] > 0)
		{
			int nowdam = skill[i][p[i]] * (10 + enh);
			--p[i];
			nowdam += calc(h, p, i);
			ans = max(ans, nowdam);
			++p[i];
		}
	}
	return ans;
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		int dam, enh;
		scanf("%d%d", &dam, &enh);
		skill[enh][++skill[enh][0]] = dam / 10;
	}
	for (int i = 0; i <= 10; ++i)
	{
		sort(skill[i] + 1, skill[i] + skill[i][0] + 1);
		p[i] = skill[i][0];
	}
	printf("%d\n", calc(0, p, 0));
	return 0;
}
