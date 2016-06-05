#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAXN 110

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
		int data;
		double weight;
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

double x[MAXN];
double y[MAXN];
bool gone[MAXN];

double dis(int p1, int p2)
{
	return sqrt((x[p1] - x[p2]) * (x[p1] - x[p2]) + (y[p1] - y[p2]) * (y[p1] - y[p2]));
}

t_heap heap(MAXN * MAXN);

int main()
{
	int i, j, n;
	double ans = 0.0;
	t_data newdata;
	t_data topdata;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%lf%lf", &x[i], &y[i]);
	}
	
	newdata.weight = 0;
	newdata.data = 1;
	heap.insert(newdata);
	
	for (i = 2; i <= n; ++i)
	{
		while (gone[heap.gettop().data])
		{
			heap.deletetop();
		}
		topdata = heap.gettop();
		gone[topdata.data] = true;
		ans += topdata.weight;
		for (j = 1; j <= n; ++j)
		{
			if (gone[j] == false)
			{
				newdata.weight = dis(j, topdata.data);
				newdata.data = j;
				heap.insert(newdata);
			}
		}
	}
	while (gone[heap.gettop().data])
	{
		heap.deletetop();
	}
	gone[heap.gettop().data] = true;
	ans += heap.gettop().weight;
	printf("%.2lf\n", ans);
	return 0;
}
