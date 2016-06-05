#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

#define MAXN 1010

// make pre-star graph
struct path
{
	int f, t, v;
}paths[2010];
int s[MAXN];
int p[MAXN];
bool gone[MAXN];

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

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
		t_data &operator = (t_data &d1)
		{
			weight = d1.weight;
			data = d1.data;
			return (*this);
		}
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
		~t_heap()
		{
			 delete [] data;
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
	private:
		int t_heapsize;
		t_data *data;
		void turnup(int p)
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

t_heap heap(20000);

int dijkstra(int pstart, int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, sizeof(gone));
	new_data.weight = 0;
	new_data.data = pstart;
	heap.insert(new_data);
	while (true)
	{
		while (st_data = heap.gettop(), gone[st_data.data] == true)
		{
			heap.deletetop();
		}
		if (heap.getsize() == 0)
		{
			break;
		}
		if (st_data.data == pend) break;
		gone[st_data.data] = true;
		for (int i = p[st_data.data]; i < p[st_data.data + 1]; ++i)
		{
			if (gone[paths[i].t] == false)
			{
				new_data.weight = st_data.weight + paths[i].v;
				new_data.data = paths[i].t;
				heap.insert(new_data);
			}
		}
	}
	return st_data.weight;
}

int main()
{
	int i, n, m;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(p, 0, sizeof(p));
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &paths[i].f, &paths[i].t, &paths[i].v);
		paths[i + m].f = paths[i].t;
		paths[i + m].t = paths[i].f;
		paths[i + m].v = paths[i].v;
		++s[paths[i].f];
		++s[paths[i].t];
	}
	sort(paths + 1, paths + 1 + m + m, cmp);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	
	printf("%d\n", dijkstra(1, n));
	
	return 0;
}
