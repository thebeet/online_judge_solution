#include <stdio.h>
#include <string.h>

#include <algorithm>

using std::swap;

int path[2097152];
int sea[1048576];

class t_data
{
	friend bool operator < (const t_data &d1, const t_data &d2)
	{
		return (d1.weight < d2.weight);
	}
	
	public:
		long long weight;
		int data;
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

int n, n2;
bool gone[2097152];
t_heap heap(2097152);

// dijkstra use heap 
long long dijkstra(int pstart, int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, (n2 + 10));
	new_data.weight = 0;
	new_data.data = pstart;
	heap.insert(new_data);
	for ( ; ;)
	{
		while (gone[heap.gettop().data] == true)
		{
			heap.deletetop();
		}
		st_data = heap.gettop();
		gone[st_data.data] = true;
		if (st_data.data == pend) break;
		new_data.data = st_data.data ^ 1;
		if (gone[new_data.data] == false)
		{
			new_data.weight = st_data.weight + (long long)sea[st_data.data >> 1];
			heap.insert(new_data);
		}
		new_data.data = st_data.data - 2;
		if ((new_data.data >= 0) && (gone[new_data.data] == false))
		{
			new_data.weight = st_data.weight + (long long)path[new_data.data];
			heap.insert(new_data);
		}
		new_data.data = st_data.data + 2;
		if ((new_data.data <= n2) && (gone[new_data.data] == false))
		{
			new_data.weight = st_data.weight + (long long)path[st_data.data];
			heap.insert(new_data);
		}
	}
	return st_data.weight;
}


int main()
{
	int i;
	int st, ed;
	int u, d;
	while (scanf("%d", &n), n > 0)
	{
		n2 = (n << 1) + 1;
		scanf("%d%d", &u, &d);
		st = (d << 1) + u;
		scanf("%d%d", &u, &d);
		ed = (d << 1) + u;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &path[i << 1]);
		}
		for (i = 0; i <= n; ++i)
		{
			scanf("%d", &sea[i]);
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &path[(i << 1) + 1]);
		}
		printf("%I64d\n", dijkstra(st, ed));
	}
	return 0;
}
