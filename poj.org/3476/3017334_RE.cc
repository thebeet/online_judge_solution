#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

char balls[100010];
int next[100010];
int prev[100010];
int head[100010];
int tail[100010];
int pos[100010];
int n;

class t_data
{
	friend bool operator < (const t_data &d1, const t_data &d2)
	{
		return ((d1.weight == d2.weight) ? (d1.data < d2.data) : (d1.weight > d2.weight));
	}
	public:
		t_data(const int d = 0, const int w = 0) :
			weight(w), data(d)
		{
		}
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
			pos[newdata.data] = heapsize;
			turnup(heapsize);
		}
		t_data &gettop() const
		{
			return data[1];
		}
		void deletetop()
		{
			swap(data[1], data[heapsize]);
			swap(pos[data[1].data], pos[data[heapsize].data]);
			--heapsize;
			turndown(1);
		}
		void deletep(const int p)
		{
			if (p == heapsize)
			{
				--heapsize;
			}
			else
			{
				swap(data[p], data[heapsize]);
				swap(pos[data[p].data], pos[data[heapsize].data]);
				--heapsize;
				turnup(p);
				turndown(p);
			}
		}
		void clean()
		{
			heapsize = 0;
		}
		int heapsize;
		t_data *data;
		void turnup(int p)
		{
			if (p > 1)
			{
				int nextp = (p >> 1);
				if (data[p] < data[nextp])
				{
					swap(data[nextp], data[p]);
					swap(pos[data[nextp].data], pos[data[p].data]);
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
					swap(pos[data[nextp].data], pos[data[p].data]);
					turndown(nextp);
				}
			}
		}
};


int main()
{
	int i;
	scanf("%s", balls + 1);
	n = strlen(balls + 1);
	t_heap heap(n + 2);
	for (i = 1; i <= n; ++i)
	{
		next[i] = i + 1;
		prev[i] = i - 1;
	}
	for (i = 1; i <= n; )
	{
		int pr(i);
		while (balls[++i] == balls[pr]);
		head[i - 1] = pr;
		tail[pr] = i - 1;
		heap.insert(t_data(pr, i - pr));
	}
	while ((heap.heapsize > 0) && (heap.gettop().weight > 1))
	{
		t_data outballs = heap.gettop();
		heap.deletetop();
		int p = outballs.data;
		int st(p);
		int prst = prev[st];
		printf("%c", balls[st]);
		while (balls[st] == balls[p])
		{
			printf(" %d", p);
			p = next[p];
		}
		printf("\n");
		next[prst] = p;
		prev[p] = prst;
		if (balls[prst] == balls[p])
		{
			int hdst = head[prst];
			head[tail[p]] = hdst;
			t_data td2 = heap.data[pos[p]];
			heap.deletep(pos[p]);
			heap.data[pos[hdst]].weight += td2.weight;
			heap.turnup(pos[hdst]);
			heap.turndown(pos[hdst]);
		}
	}
	return 0;
}
