#include <stdio.h>
#include <algorithm>

using std::max;
using std::swap;

bool mole[16][32][32];
int dp[16][32][32];
int gcdans[8][8];

template <typename T_INT>
T_INT gcd(T_INT a, T_INT b)
{
	T_INT r;
	if (b < 0)
	{
		b = -b;
	}
	if (a < 0)
	{
		a = -a;
	}
	if (b > a)
	{
		swap(a, b);
	}
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	for (int i = 0; i <= 5; ++i)
	{
		for (int j = 0; j <= 5; ++j)
		{
			gcdans[i][j] = gcd(i, j);
		}
	}
	
	int n, d, m;
	int x, y, t;
	while (scanf("%d%d%d", &n, &d, &m), n > 0)
	{
		int i, it, ix, iy, dx, dy, dd, g, op1, op2, ans;
		dd = d * d;
		ans = 0;
		memset(dp, 0, sizeof(dp));
		memset(mole, false, sizeof(mole));
		
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &x, &y, &t);
			mole[t][x + d + d][y + d + d] = true;
		}
		for (it = 1; it <= 10; ++it)
		{
			for (ix = 1; ix <= n + d + d; ++ix)
			{
				for (iy = 1; iy <= n + d + d; ++iy)
				{
					for (dx = 0; dx <= d; ++dx)
					{
						for (dy = 0; dy <= d; ++dy)
						{
							if ((dx * dx) + (dy * dy) <= dd)
							{
								if ((dx == dy) && (dx == 0))
								{
									dp[it][ix][iy] = max(dp[it - 1][ix][iy], dp[it][ix][iy]);
								}
								else
								{
									for (op1 = -1; op1 <= 1; op1 += 2)
									{
										for (op2 = -1; op2 <= 1; op2 += 2)
										{
											int sum = 0;
											for (g = 0; g <= gcdans[dx][dy]; ++g)
											{
												if (mole[it][ix + op1 * dx * g / gcdans[dx][dy]][iy + op2 * dy * g / gcdans[dx][dy]])
												{
													++sum;
												}
											}
											dp[it][ix + op1 * dx][iy + op2 * dy] = max(dp[it - 1][ix + op1 * dx][iy + op2 * dy] + sum, dp[it][ix + op1 * dx][iy + op2 * dy]);
										}
									}
								}
								
							}
						}
					}
					ans = max(ans, dp[it][ix][iy]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
