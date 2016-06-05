#include <iostream>
#include <algorithm>

#define MAXN 1000010

using namespace std;

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
		void insert(int newweight, int newdata)
		{
			data[++t_heapsize].weight = newweight;
			data[t_heapsize].data = newdata;
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

t_heap heap(MAXN);

int number[MAXN];

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &number[i]);
	}
	
	heap.clean();
	
	for (i = 1; i <= m; ++i)
	{
		heap.insert(number[i], i);
	}
	printf("%d", heap.gettop().weight);
	for (i = m + 1; i <= n; ++i)
	{
		heap.insert(number[i], i);
		while (heap.gettop().data + m <= i)
		{
			heap.deletetop();
		}
		printf(" %d", heap.gettop().weight);
	}
	printf("\n");
	for (i = 1; i <= n; ++i)
	{
		number[i] = -number[i];
	}
	
	heap.clean();
	
	for (i = 1; i <= m; ++i)
	{
		heap.insert(number[i], i);
	}
	printf("%d", -heap.gettop().weight);
	for (i = m + 1; i <= n; ++i)
	{
		heap.insert(number[i], i);
		while (heap.gettop().data + m <= i)
		{
			heap.deletetop();
		}
		printf(" %d", -heap.gettop().weight);
	}
	printf("\n");
	return 0;
}	
