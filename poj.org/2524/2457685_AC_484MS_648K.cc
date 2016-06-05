#include <stdio.h>
#include <string.h>

#define MAXN 50010

class t_set
{
	public:
		t_set(int n)
		{
			father = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; ++i)
			{
				father[i] = i;
				rank[i] = 0;
			}
		}
		~t_set()
		{
			delete [] father;
			delete [] rank;
		}
		void clean(int n)
		{
			delete [] father;
			delete [] rank;
			father = new int[n];
			rank = new int[n];
			for (int i = 0; i < n; ++i)
			{
				father[i] = i;
				rank[i] = 0;
			}
		}
		int findfather(int p)
		{
			if (father[p] == p) 
			{
				return p;
			}
			else
			{
				return (father[p] = findfather(father[p]));
			}
		}
		void connect(int p1, int p2)
		{
			int father1 = findfather(p1);
			int father2 = findfather(p2);
			if (rank[father1] < rank[father2])
			{
				father[father1] = father2;
			}
			else 
			{
				father[father2] = father1;
				if (rank[father1] == rank[father2])
				{
					++rank[father1];
				}
			}				
		}
		
	private:
		int *father;
		int *rank;
};

t_set myset(1);

bool use[MAXN];

int main()
{
	int ti, i, n, m, a, b, ans;
	ti = 0;
	while (scanf("%d%d", &n, &m), n > 0)
	{
		memset(use, false, sizeof(use));
		myset.clean(n + 1);
		ans = 0;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d", &a, &b);
			myset.connect(a, b);
		}
		
		for (i = 1; i <= n; ++i)
		{
			use[myset.findfather(i)] = true;
		}
		
		for (i = 1; i <= n; ++i)
		{
			if (use[i])
			{
				++ans;
			}
		}
		printf("Case %d: %d\n", ++ti, ans);
	}
	return 0;
}
