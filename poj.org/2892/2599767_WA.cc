#include <cstdio>
#include <cstring>

const int SIZE = 50010;

class t_TreeArray
{
public:
	void init(const int n)
	{
		 memset(data, 0, sizeof(int) * (n + 1));
		 size = n;
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
	
private:
	int data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

t_TreeArray treearray;
int des[SIZE];
int n;

int binaryfind(int lo, int hi, int key)
{
	int mid;
	while (lo + 1 < hi)
	{
		mid = (lo + hi) >> 1;
		if (treearray.getsum(mid) <= key)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}
	return lo;
}

int query(int p)
{
	int key = treearray.getsum(p);
	return (binaryfind(p, n + 1, key) - binaryfind(0, p, key - 1) - 1);
}

int main()
{
	int i, j, m;
	char op[4];
	scanf("%d%d", &n, &m);
	treearray.init(n + 1);
	memset(des, 0, sizeof(des));
	for (i = 1; i <= m; ++i)
	{
		scanf("%s", op);
		switch (op[0])
		{
		case 'D':
			{
				scanf("%d", &des[++des[0]]);
				treearray.add(des[des[0]], 1);
				break;
			}
		case 'R':
			{
				treearray.add(des[des[0]--], -1);
				break;
			}
		case 'Q':
			{
				int p;
				scanf("%d", &p);
				printf("%d\n", query(p));
			}
		}
	}
	return 0;
}
