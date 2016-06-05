#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 1000100

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

class t_data
{
	friend void swap(t_data &a, t_data &b)
	{
		t_data tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	friend bool operator > (t_data d1,t_data d2)
	{
		return (d1.weight > d2.weight);
	}
	friend bool operator < (t_data d1,t_data d2)
	{
		return (d1.weight < d2.weight);
	}
	
	public:
		int weight, data;
};

class t_heap
{
	public:
		t_heap(int n)
		{
			 data = new t_data[n];
			 memset(data, 0, sizeof(t_data) * n);
			 t_heapsize = 0;
		}
		int getsize()
		{
			return t_heapsize;
		}
		void insert(t_data newdata)
		{
			data[++t_heapsize] = newdata;
			turnup(t_heapsize);
		}
		t_data &gettop()
		{
			return data[1];
		}
		void deletetop()
		{
			swap(data[1], data[t_heapsize--]);
			turndown(1);
		}
		void clean()
		{
			t_heapsize = 0;
		}
	private:
		int t_heapsize;
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[nextp] > data[p])
				{
					swap(data[nextp], data[p]);
					turnup(nextp);
				}
			}
		}
		void turndown(int p)
		{
			int nextp = (p << 1);
			if (nextp <= t_heapsize)
			{
				if ((nextp < t_heapsize) && (data[nextp] > data[nextp + 1]))
				{
					++nextp;
				}
				if (data[nextp] < data[p])
				{
					swap(data[nextp], data[p]);
					turndown(nextp);
				}
			}
		}
};

// make pre-star graph
struct path
{
	int f, t, v;
}paths[2][1000010];
int s[2][MAXN];
int p[2][MAXN];
int ans[2][MAXN];
bool gone[2][MAXN];

t_heap heap(1000010);

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

// dijkstra use heap 
void dijkstra(int k, int pstart)
{
	t_data st_data;
	t_data new_data;
	memset(ans[k], 0, sizeof(ans[k]));
	memset(gone[k], false, sizeof(gone[k]));
	new_data.weight = 0;
	new_data.data = pstart;
	heap.insert(new_data);
	while (true)
	{
		while (st_data = heap.gettop(), ((heap.getsize() != 0) && (gone[k][st_data.data])))
		{
			heap.deletetop();
		}
		if (heap.getsize() == 0)
		{
			break;
		}
		ans[k][st_data.data] = st_data.weight;
		gone[k][st_data.data] = true;
		for (int i = p[k][st_data.data]; i < p[k][st_data.data + 1]; ++i)
		{
			if (gone[k][paths[k][i].t] == false)
			{
				new_data.weight = st_data.weight + paths[k][i].v;
				new_data.data = paths[k][i].t;
				heap.insert(new_data);
			}
		}
	}
}

int main()
{
	int i, k, n, m, st, total;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	scanf("%d%d%d", &n, &m, &st);
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &paths[0][i].f, &paths[0][i].t, &paths[0][i].v);
		paths[1][i].f = paths[0][i].t;
		paths[1][i].t = paths[0][i].f;
		paths[1][i].v = paths[0][i].v;
		++s[0][paths[0][i].f];
		++s[1][paths[1][i].f];
	}
	sort(paths[1] + 1, paths[1] + 1 + m, cmp);
	p[0][1] = 1;
	p[1][1] = 1;
	for (k = 0; k <= 1; k++)
	{
		sort(paths[k] + 1, paths[k] + 1 + m, cmp);
		p[k][1] = 1;
		for (i = 1; i <= n; ++i)
		{
			p[k][i + 1] = p[k][i] + s[k][i];
		}
	}
	dijkstra(0, st);
	heap.clean();
	dijkstra(1, st);
	for (i = 1; i <= n; ++i)
	{
		ans[0][i] += ans[1][i];
		total = MAX(total, ans[0][i]);
	}
	printf("%d\n", total);
	return 0;	
}
