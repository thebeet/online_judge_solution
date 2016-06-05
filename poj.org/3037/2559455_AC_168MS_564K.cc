#include <stdio.h>
#include <string.h>

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
		double weight;
		int data;
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

const int size = 128 * 128;
const int towards[4] = { 1, -1, 100, -100};

double tmap[size];
bool gone[size];
int n, m;

t_heap heap(size);

// dijkstra use heap 
double dijkstra(int pstart, int pend)
{
	t_data st_data;
	t_data new_data;
	memset(gone, false, sizeof(gone));
	new_data.weight = 0;
	new_data.data = pstart;
	heap.insert(new_data);
	for ( ; ; )
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
		if (st_data.data == pend) break;
		
		for (int i = 0; i < 4; ++i)
		{
			if (((st_data.data % 100) == 0) && (towards[i] == -1))
			{
				continue;
			}
			if (((st_data.data % 100) == m - 1) && (towards[i] == 1))
			{
				continue;
			}
			if (((st_data.data / 100) == 0) && (towards[i] == -100))
			{
				continue;
			}
			if (((st_data.data / 100) == n - 1) && (towards[i] == 100))
			{
				continue;
			}
			if (gone[st_data.data + towards[i]] == false)
			{
				new_data.weight = st_data.weight + tmap[st_data.data];
				new_data.data = st_data.data + towards[i];
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

int main()
{
	int i, j, v;
	scanf("%d%d%d", &v, &n, &m);
	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			int m;
			scanf("%d", &m);
			if (m > 0)
			{
				tmap[i * 100 + j] = (double)(1 << m);
			}
			else
			{
				tmap[i * 100 + j] = 1.0 / (double)(1 << (-m));
			}
		}
	}
	printf("%.2lf\n", dijkstra(0, (n - 1) * 100 + m - 1) / tmap[0] / v);
	return 0;
}
