#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 100010;

struct dog
{
	int id;
	int pr;
}dogs[MAXN];

int rank[MAXN];

bool cmpdog(const dog &dog1, const dog &dog2)
{
	return (dog1.pr < dog2.pr);
}

struct query
{
	int st;
	int ed;
	int id;
	int nth;
}querys[MAXN];

bool cmpquery(const query &q1, const query &q2)
{
	return (q1.st < q2.st);
}

int ans[MAXN];

class t_Segtree
{
public:
	t_Segtree()
	{
	}
	~t_Segtree()
	{
	}
	void init(int n)
	{
		size = n;
		step = 0;
		n--;
		while (n > 0)
		{
			++step;
			n >>= 1;
		}
		memset(data, 0, size + 1);
		step = 1 << step;
	}
	void add(int p, int d)
	{
		p += step;
		while (p > 0)
		{
			data[p] += d;
			p >>= 1;
		}
	}
	int getvalue(int nth)
	{
		int p = 1;
		while (p < step)
		{
			p <<= 1;
			if (data[p] < nth)
			{
				nth -= data[p];
				++p;
			}
		}
		return p - step;
	}
private:
	int data[MAXN * 4];
	int size;
	int step;
};

t_Segtree tree;

int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	memset(dogs, 0, sizeof(dogs));
	memset(querys, 0, sizeof(querys));
	memset(rank, 0, sizeof(rank));
	memset(ans, 0, sizeof(ans));
	
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &dogs[i].pr);
		dogs[i].id = i;
	}
	sort(dogs + 1, dogs + 1 + n, cmpdog);
	
	for (i = 1; i <= n; ++i)
	{
		rank[dogs[i].id] = i;
	}
	
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &querys[i].st, &querys[i].ed, &querys[i].nth);
		querys[i].id = i;
	}
	sort(querys + 1, querys + 1 + m, cmpquery);
	
	tree.init(n);
	int prst = MAXN;
	int pred = -1;
	for (i = 1; i <= m; ++i)
	{
		if (querys[i].st > pred)
		{
			for (j = prst; j <= pred; ++j)
			{
				tree.add(rank[j], -1);
			}
			prst = querys[i].st;
			pred = prst - 1;
		}
		for (j = prst; j < querys[i].st; ++j)
		{
			tree.add(rank[j], -1);
		}
		for (j = pred + 1; j <= querys[i].ed; ++j)
		{
			tree.add(rank[j], 1);
		}
		ans[querys[i].id] = dogs[tree.getvalue(querys[i].nth)].pr;
		prst = querys[i].st;
		pred = querys[i].ed;
	}
	for (i = 1; i <= m; ++i)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
