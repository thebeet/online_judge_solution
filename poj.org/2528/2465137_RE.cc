#include <stdio.h>
#include <algorithm>

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

t_heap heap(10010);

struct event
{
	int id;
	int time;
	int height;
	bool isbegin;
}events[20010];

bool cmp(event e1, event e2)
{
	return (e1.time < e2.time);
}

bool isend[10010];
bool isappear[10010];

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 1; ti <= tn; ++ti)
	{
		int i, n, st, ed, ans;
		t_data newdata;
		t_data topdata;
		
		heap.clean();
		memset(isend, false, sizeof(isend));
		memset(isappear, false, sizeof(isappear));
		ans = 0;
		
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d%d", &st, &ed);
			events[i].time = st;
			events[i].height = i; 
			events[i].isbegin = true; 
			events[i + n].time = ed + 1;
			events[i + n].height = i; 
			events[i + n].isbegin = false;
		}
		sort(events + 1, events + 1 + n + n, cmp);
		
		for (i = 1; i <= n + n; ++i)
		{
			for (;;++i)
			{
				if (events[i].isbegin)
				{
					newdata.weight = events[i].height;
					heap.insert(newdata);
				}
				else
				{
					isend[events[i].height] = true;
				}
				if (events[i].time != events[i + 1].time)
				{
					break;
				}
			}
			while ((topdata = heap.gettop(), isend[topdata.weight]))
			{
				heap.deletetop();
			}
			isappear[topdata.weight] = true;
		}
		
		for (i = 1; i <= n; ++i)
		{
			if (isappear[i])
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}		
