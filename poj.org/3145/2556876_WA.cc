#include <stdio.h>
#include <string.h>

const int SIZE = 524288;
const int Range = 500000;

class t_TreeList
{
public:
	t_TreeList(void)
	{
		 size = Range;
	}
	virtual ~t_TreeList()
	{
	}
	void init(void)
	{
		 memset(data, 0, sizeof(data));
	}
	void add(int k)
	{
		while (k <= size)
		{
			++data[k];
			k += lowbit(k);
		}
	}
	int getsum(int k) //get sum for 1 to k
	{
		int sum = 0;
		while (k > 0)
		{
			sum += data[k];
			k -= lowbit(k);
		}
		return sum;
	}
	int data[SIZE];
	int size;
private:
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeList tree;

const int dv = 1000;

int reminds[dv];
int pos[dv];
int calc[dv];
int b[65536];
int revp[SIZE];

int main()
{
	int ti = 0;
	int n;
	char op[4];
	while (scanf("%d", &n), (n > 0))
	{
		++ti;
		if (ti > 1)
		{
			printf("\n");
		}
		printf("Case %d:\n", ti);
		
		int i, j, m;
		memset(reminds, 1, sizeof(reminds));
		memset(pos, 0, sizeof(pos));
		memset(calc, 0, sizeof(calc));
		int k = 0;
		tree.init();
		
		for (i = 1; i <= n; ++i)
		{
			scanf("%s%d", op, &m);
			if (op[0] == 'A')
			{
				if (k == 0)
				{
					printf("-1\n");
					continue;
				}
				if (m < dv)
				{
					
					for (j = calc[m] + 1; j <= k; ++j)
					{
						int r = b[j] % m;
						if (r <= reminds[m])
						{
							reminds[m] = r;
							pos[m] = j;
						}
					}
					calc[m] = k;
					printf("%d\n", pos[m]);
				}
				else
				{
					int ans = 0;
					int lo, hi, mid, th;
					for (th = m - 1; th <= Range; th += m)
					{
						hi = th;
						lo = hi - m + 1;
						if (revp[lo] > 0)
						{
							if (revp[lo] > ans)
							{
								ans = revp[lo];
							}
						}
						else
						{
							int s = tree.getsum(lo);
							if (tree.getsum(hi) == s)
							{
								continue;
							}
							while (lo + 1 < hi)
							{
								mid = (lo + hi) >> 1;
								if (tree.getsum(mid) > s)
								{
									hi = mid;
								}
								else
								{
									lo = mid;
								}
							}
							if (revp[hi] > ans)
							{
								ans = revp[hi];
							}
						}
					}
					printf("%d\n", ans);
				}
			}
			else
			{
				++k;
				b[k] = m;
				revp[m] = k;
				tree.add(m);
			}
		}
	}
	return 0;
}

