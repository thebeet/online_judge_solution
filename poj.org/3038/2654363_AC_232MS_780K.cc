#include <stdio.h>
#include <algorithm>

using namespace std;

typedef int t_data;

class t_heap
{
	public:
		t_heap(const int n)
		{
			 data = new t_data[n];
			 memset(data, 0, sizeof(t_data) * n);
			 heapsize = 0;
		}
		~t_heap()
		{
			 delete [] data;
		}
		void insert(const t_data &newdata)
		{
			data[++heapsize] = newdata;
			turnup(heapsize);
		}
		t_data &gettop() const
		{
			return data[1];
		}
		void deletetop()
		{
			swap(data[1], data[heapsize--]);
			turndown(1);
		}
		void clean()
		{
			heapsize = 0;
		}
		int heapsize;
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[p] > data[nextp])
				{
					swap(data[nextp], data[p]);
					turnup(nextp);
				}
			}
		}
		void turndown(int p)
		{
			int nextp = (p << 1);
			if (nextp <= heapsize)
			{
				if ((nextp < heapsize) && (data[nextp + 1] > data[nextp]))
				{
					++nextp;
				}
				if (data[nextp] > data[p])
				{
					swap(data[nextp], data[p]);
					turndown(nextp);
				}
			}
		}
};

struct path
{
	void eq(int ff, int tt, int qq)
	{
		f = ff;
		t = tt;
		q = qq;
	}
	int f, t, q;
}paths[2][65536];
bool operator < (const path &p1, const path &p2)
{
	return (p1.f < p2.f);
}

int nn[2];

int main()
{
	int i, j, k, n, c, f, t, q, h;
	scanf("%d%d%d", &k, &n, &c);
	t_heap heap(128);
	for (i = 1; i <= k; ++i)
	{
		scanf("%d%d%d", &f, &t, &q);
		if (f < t)
		{
			paths[0][++nn[0]].eq(f, t, q);
		}
		else
		{
			paths[1][++nn[1]].eq(t, f, q);
		}
	}
	sort(paths[0] + 1, paths[0] + nn[0] + 1);
	sort(paths[1] + 1, paths[1] + nn[1] + 1);
	
	int ans = 0;
	for (h = 0; h <= 1; ++h)
	{
		heap.clean();
		for (i = 1; i <= nn[h]; ++i)
		{
			for (j = heap.heapsize; j >= 1; )
			{
				if ((j << 1) <= heap.heapsize)
				{
					break;
				}
				if (heap.data[j] <= paths[h][i].f)
				{
					swap(heap.data[j], heap.data[heap.heapsize--]);
					heap.turnup(j);
					if (j > heap.heapsize)
					{
						--j;
					}
					++ans;
				}
				else
				{
					--j;
				}
			}
			for (j = 1; j <= paths[h][i].q; ++j)
			{
				if (heap.heapsize < c)
				{
					heap.insert(paths[h][i].t);
				}
				else if (heap.gettop() > paths[h][i].t)
				{
					heap.data[1] = paths[h][i].t;
					heap.turndown(1);
				}
				else
				{
					//break;
				}
			}
		}
		ans += heap.heapsize;
	}
	printf("%d\n", ans);
	return 0;
}
/*
4 8 3
1 3 2
2 8 3
4 7 1
8 3 2
6
*/
