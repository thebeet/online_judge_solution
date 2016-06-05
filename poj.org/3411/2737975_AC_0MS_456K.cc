#include <iostream>
#include <algorithm>

using namespace std;

struct path
{
	int a, b, c, p, r;
}paths[16];
int s[16];
int pp[16];

bool operator < (const path &p1, const path &p2)
{
	return (p1.a < p2.a);
}

class t_data
{
	friend bool operator < (const t_data &d1, const t_data &d2)
	{
		return (d1.weight < d2.weight);
	}
	
	public:
		int weight, data;
};

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
	private:
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[p] < data[nextp])
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
				if ((nextp < heapsize) && (data[nextp + 1] < data[nextp]))
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

t_heap heap(16384);

bool gone[16384];

// dijkstra use heap 
int dijkstra(int pstart, int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, sizeof(gone));
	new_data.weight = 0;
	new_data.data = (1 << (pstart + 3)) + pstart;
	heap.insert(new_data);
	while (true)
	{
		while ((heap.heapsize != 0) && (gone[heap.gettop().data] == true))
		{
			heap.deletetop();
		}
		if (heap.heapsize == 0)
		{
			break;
		}
		st_data = heap.gettop();
		gone[st_data.data] = true;
		int st = (st_data.data & 15);
		if (st == pend) break;
		for (int i = pp[st]; i < pp[st + 1]; ++i)
		{
			int tar = paths[i].b + ((st_data.data & 0x3FF0) | (1 << (3 + paths[i].b)));
			if (gone[tar] == false)
			{
				if ((st_data.data & (1 << (3 + paths[i].c))) > 0)
				{
					new_data.weight = st_data.weight + paths[i].p;
				}
				else
				{
					new_data.weight = st_data.weight + paths[i].r;
				}
				new_data.data = tar;
				heap.insert(new_data);
			}
		}
	}
	if (heap.heapsize == 0)
	{
		return -1;
	}
	else
	{
		return st_data.weight;
	}
}

int main()
{
	int i, n, m;
	cin >> n >> m;
	for (i = 1; i <= m; ++i)
	{
		cin >> paths[i].a >> paths[i].b >> paths[i].c >> paths[i].p >> paths[i].r;
		++s[paths[i].a];
	}
	sort(paths + 1, paths + 1 + m);
	pp[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		pp[i + 1] = pp[i] + s[i];
	}
	
	int ans = dijkstra(1, n);
	
	if (ans >= 0)
	{
		cout << ans << endl;
	}
	else
	{
		cout << "impossible" << endl;
	}
	return 0;
}
