#include <stdio.h>
#include <string.h>
#include <algorithm>

using std::swap;

char map[64][64];
bool gone[64][64];
int path[128][128];

struct t_queue
{
	void add(int newx, int newy, int news)
	{
		gone[newx][newy] = true;
		x[++end] = newx;
		y[end] = newy;
		s[end] = news;
	}
	int go(int newx, int newy, int news)
	{
		if ((gone[newx][newy] == false) && (map[newx][newy] < 127))
		{
			add(newx, newy, news);
			return map[newx][newy];
		}
		else
		{
			return 0;
		}
	}
	int x[4096];
	int y[4096];
	int s[4096];
	int end;
}queue;

void bfs(int x, int y, int id)
{
	int i;
	
	memset(gone, false, sizeof(gone));
	
	queue.end = 0;
	queue.add(x, y, 0);
	
	for (i = 1; i <= queue.end; ++i)
	{
		int tx = queue.x[i];
		int ty = queue.y[i];
		int ts = queue.s[i] + 1;
		path[id][queue.go(tx + 1, ty, ts)] = ts;
		path[id][queue.go(tx - 1, ty, ts)] = ts;
		path[id][queue.go(tx, ty + 1, ts)] = ts;
		path[id][queue.go(tx, ty - 1, ts)] = ts;
	}
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

t_heap heap(10210);
bool intree[128];
char mapbuf[128];

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int i, j, m, n, ;
		char alien;
		
		alien = 0;
		memset(map, 127, sizeof(map));
		
		scanf("%d%d", &m, &n);
		gets(mapbuf + 1);
		for (i = 1; i <= n; ++i)
		{
			gets(mapbuf + 1);
			for (j = 1; j <= m; ++j)
			{
				switch (mapbuf[j])
				{
				case ' ':
					map[i][j] = 0;
					break;
				case 'A': case 'S':
					map[i][j] = ++alien;
				}
			}
		}
		
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= m; ++j)
			{
				if ((map[i][j] > 0) && (map[i][j] < 127))
				{
					bfs(i, j, map[i][j]);
				}
			}
		}
		
		int ans = 0;
		t_data newdata;
		heap.clean();
		memset(intree, false, sizeof(intree));
		intree[1] = true;
		for (i = 2; i <= alien; ++i)
		{
			newdata.data = i;
			newdata.weight = path[1][i];
			heap.insert(newdata);
		}
		for (i = 2; i <= alien; ++i)
		{
			while (intree[heap.gettop().data])
			{
				heap.deletetop();
			}
			ans += heap.gettop().weight;
			int f = heap.gettop().data;
			intree[f] = true;
			for (j = 1; j <= alien; ++j)
			{
				if (intree[j] == false) 
				{
					newdata.data = j;
					newdata.weight = path[f][j];
					heap.insert(newdata);
				}
			}
		}
		
		printf("%d\n", ans);
	}
	return 0;
}
