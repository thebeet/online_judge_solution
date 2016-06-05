#include <stdio.h>
#include <iostream>
#include <algorithm>

#define MAXN 80010

#define INT long long

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
			if (p <= 1) return;
			int nextp = p / 2;
			if (data[nextp] < data[p])
			{
				swap(data[nextp], data[p]);
				turnup(nextp);
			}
		}
		void turndown(int p)
		{
			int nextp = p * 2;
			if (nextp <= t_heapsize)
			{
				if ((nextp < t_heapsize) && (data[nextp] < data[nextp + 1]))
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

t_heap heap(MAXN);

struct event
{
	int id;
	int time;
	int height;
}events[MAXN * 2];

bool cmp(event e1, event e2)
{
	return (e1.time < e2.time);
}

char isend[MAXN];

int main()
{
	int i, n, ans;
	
	heap.clean();
	memset(isend, 0, sizeof(isend));
	memset(events, 0, sizeof(events));
	ans = 0;
	
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		int st, ed, he;
		cin >> st >> ed >> he;
		events[i].id = i; 
		events[i].time = st;
		events[i].height = he; 
		events[i + n].id = i; 
		events[i + n].time = ed;
		events[i + n].height = he; 
	}
	sort(events + 1, events + 1 + n + n, cmp);
	
	int pr_h = 0;
	int pr_x = 0;
	INT sum = 0;
	
	t_data newdata;
	newdata.weight = 0;
	newdata.data = 0;
	heap.insert(newdata);
	
	for (i = 1; i <= n + n; ++i)
	{
		while (true)
		{
			if (isend[events[i].id] == 0)
			{
				newdata.weight = events[i].height;
				newdata.data = events[i].id;
				heap.insert(newdata);
				isend[events[i].id] = 1;
			}
			else
			{
				isend[events[i].id] = 2;
			}
			if (events[i].time != events[i + 1].time)
			{
				break;
			}
			++i;
		}
		while (heap.getsize() != 0)
		{
			if (isend[heap.gettop().data] == 2)
			{
				heap.deletetop();
			}
			else
			{
				break;
			}					
		}
		sum += (INT)((events[i].time - pr_x)) * (INT)(pr_h);
		pr_x = events[i].time;
		pr_h = heap.gettop().weight;
	}
	cout << sum << endl;
	return 0;
}
