#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int SIZE = 524288 * 2;

struct point
{
	int x, y;
	int ans;
};

struct id
{
	int i;
};

id ind[65536];

point ps[65536];
point qps[65536];

bool operator < (const point &p1, const point &p2)
{
	return (p1.x < p2.x);
}

bool operator < (const id &i1, const id &i2)
{
	return (qps[i1.i].x < qps[i2.i].x);
}

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

t_TreeArray ta, ta2;

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, n, m;
		scanf("%d%d", &n, &m);
		ta.init(500000);
		ta2.init(500000);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d%d", &ps[i].x, &ps[i].y);
			++ps[i].y;
			ta2.add(ps[i].y, 1);
		}
		sort(ps + 1, ps + 1 + n);
		ps[n + 1].x = 2000000000;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &qps[i].x, &qps[i].y);
			ind[i].i = i;
		}
		sort(ind + 1, ind + 1 + m);
		j = 1;
		for (i = 1; i <= m; ++i)
		{
			int t = ind[i].i;
			//printf("==%d\n", qps[t].x);
			while (ps[j].x < qps[t].x)
			{
				ta.add(ps[j].y, 1);
				ta2.add(ps[j].y, -1);
				++j;
			}
			qps[t].ans = ta.getsum(1, qps[t].y) + ta2.getsum(qps[t].y + 1, 500000);
			qps[t].ans = abs(n - 2 * qps[t].ans);
		}
		for (i = 1; i <= m; ++i)
		{
			printf("%d\n", qps[i].ans);
		}
		if (ti != tn)
		{
			printf("\n");
		}
	}
}
