#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 50010;

int weight[MAXN];

struct path
{
	int f, t, q;
}paths[100010];
int s[MAXN];
int p[MAXN];

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
		long long weight;
		int edgesum;
		int data;
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
					if (nextp > 0)
					{
						turnup(nextp);
					}
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

bool gone[MAXN];
long long ans[MAXN];

t_heap heap(MAXN);

// dijkstra use heap 
int dijkstra(int pstart, int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, sizeof(gone));
	new_data.weight = 0;
	new_data.edgesum = 0;
	new_data.data = pstart;
	heap.insert(new_data);
	while (true)
	{
		while ((heap.getsize() != 0) && (gone[heap.gettop().data] == true))
		{
			heap.deletetop();
		}
		if (heap.getsize() == 0)
		{
			break;
		}
		st_data = heap.gettop();
		gone[st_data.data] = true;
		ans[st_data.data] = st_data.weight;
		if (st_data.data == pend) break;
		for (int i = p[st_data.data]; i < p[st_data.data + 1]; ++i)
		{
			if (gone[paths[i].t] == false)
			{
				new_data.edgesum = st_data.edgesum + paths[i].q;
				new_data.data = paths[i].t;
				new_data.weight = (long long)new_data.edgesum * (long long)weight[new_data.data];
				heap.insert(new_data);
			}
		}
	}
	if (heap.getsize() == 0)
	{
		return -1;
	}
	else
	{
		return st_data.weight;
	}
}

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, n, m;
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &weight[i]);
		}
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &paths[i].f, &paths[i].t, &paths[i].q);
			paths[i + m].f = paths[i].t;
			paths[i + m].t = paths[i].f;
			paths[i + m].q = paths[i].q;
			++s[paths[i].f];
			++s[paths[i].t];
		}
		sort(paths + 1, paths + 1 + m + m, cmp);
		p[1] = 1;
		for (i = 1; i <= n; ++i)
		{
			p[i + 1] = p[i] + s[i];
		}
		dijkstra(1, 0);
		long long sum = 0;
		for (i = 1; i <= n; ++i)
		{
			sum += ans[i];
		}
		cout << sum << endl;
	}
	return 0;
}
