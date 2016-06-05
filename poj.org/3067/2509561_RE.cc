#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define SIZE 1024

class t_TreeList
{
public:
	void init(const int n)
	{
		 memset(data, 0, sizeof(int) * n);
		 size = n - 1;
	}
	virtual ~t_TreeList()
	{
	}
	void add(int k, int newdata)
	{
		while (k <= size)
		{
			data[k] += newdata;
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
	int getsum(int f, int t) //get sum for f to t
	{
		return (getsum(t) - getsum(f - 1));
	}
	
private:
	int data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeList treelist;
int inp[1024][1024];

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int i, n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		treelist.init(m);
		for (i = 1; i <= k; ++i)
		{
			int f, t;
			scanf("%d%d", &f, &t);
			inp[f][++inp[f][0]] = t;
		}
		
		int ans = 0;
		for (i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= inp[i][0]; ++j)
			{
				ans += treelist.getsum(m - inp[i][j]);
			}
			for (int j = 1; j <= inp[i][0]; ++j)
			{
				treelist.add(m - inp[i][j] + 1, 1);
			}
		}
		printf("Test case %d: %d\n", ti, ans);
	}
	return 0;
}
