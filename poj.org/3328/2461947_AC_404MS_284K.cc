#include <stdio.h>
#include <string.h>

#define MAXN 10000;

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
		int weight, x, y;
		int isleft;
		t_data &operator = (t_data &d1)
		{
			weight = d1.weight;
			x = d1.x;
			y = d1.y;
			isleft = d1.isleft;
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

bool gone[75][75][2];
char map[75][75];

t_heap heap(5000);

int main()
{
	int n, m;
	while (scanf("%d%d", &m, &n), n > 0)
	{
		int i, j, x, y;
		t_data new_data; 
		t_data st;
		char inp[10];
		
		heap.clean();
		memset(gone, false, sizeof(gone));
		memset(map, 'X', sizeof(map));
		for (i = 3; i <= n + 2; ++i)
		{
			for (j = 3; j <= m + 2; ++j)
			{
				scanf("%s", inp);
				map[i][j] = inp[0];
				if (inp[0] == 'T')
				{
					map[i][j] = '0';
				}
				else
				{
					map[i][j] = inp[0];
				}
				if (map[i][j] == 'S')
				{
					new_data.x = i;
					new_data.y = j;
					new_data.weight = 0;
					new_data.isleft = 1;
					heap.insert(new_data);
					new_data.isleft = 0;
					heap.insert(new_data);
				}
			}
		}
		while (true)
		{
			int yst, yed;
			while ((st = heap.gettop()), ((heap.getsize() != 0) && (gone[st.x][st.y][st.isleft])))
			{
				heap.deletetop();
			}
			if (heap.getsize() == 0)
			{
				break;
			}
			gone[st.x][st.y][st.isleft] = true;
			/*printf("%d %d %d ", st.x, st.y, st.weight); 
			if (st.isleft) printf("left\n"); else printf("right\n");*/
			if (map[st.x][st.y] == '0')
			{
				break;
			}
			if (st.isleft)
			{
				yst = 1;
				yed = 3;
			}
			else
			{
				yst = -3;
				yed = -1;
			}
			for (x = -2; x <= 2; ++x)
			{
				for (y = yst; y <= yed; ++y)
				{
					if (((x + y) <= 3) && ((x + y) >= -3) && ((x - y) <= 3) && ((x - y) >= -3))
					{
						if ((gone[st.x + x][st.y + y][st.isleft ^ 1] == false) && (map[st.x + x][st.y + y] <= '9'))
						{		 
							new_data.x = st.x + x;
							new_data.y = st.y + y;
							new_data.weight = st.weight + map[st.x + x][st.y + y] - '0';
							new_data.isleft = st.isleft ^ 1;
							heap.insert(new_data);
						}
					}
				}
			}
		}
		if (heap.getsize() == 0)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", st.weight);
		}
	}
	return 0;
}
