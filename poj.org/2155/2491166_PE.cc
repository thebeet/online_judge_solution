#include <stdio.h>
#include <iostream>

using namespace std;

#define SIZE 1010

class t_TreeList
{
public:
	t_TreeList(const int n)
	{
		 memset(data, 0, sizeof(int) * n);
		 size = n - 1;
	}
	virtual ~t_TreeList()
	{
	}
	void add(int k, int newdata)
	{
		while (k <= size)
		{
			data[k] += newdata;
			k += lowbit(k);
		}
	}
	int getsum(int k) //get sum for 1 to k
	{
		int sum = 0;
		while (k > 0)
		{
			sum += data[k];
			k -= lowbit(k);
		}
		return sum;
	}
	int getsum(int f, int t) //get sum for f to t
	{
		return (getsum(t) - getsum(f - 1));
	}
	
private:
	int data[SIZE];
	int size;
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
};

class t_TreeList2D
{
public:
	t_TreeList2D()
	{
	}
	void init(int newx, int newy)
	{
		memset(data, 0, sizeof(data));
		sizex = newx;
		sizey = newy;
	}		
	void add(int x, int y, int newdata)
	{
		int tx, ty;
		tx = x;
		while (tx <= sizex)
		{
			ty = y;
			while (ty <= sizey)
			{
				data[tx][ty] += newdata;
				ty += lowbit(ty);
			}
			tx += lowbit(tx);
		}
	}
	int getsum(int x, int y) //get sum for 1,1 to x,y
	{
		int sum = 0;
		int tx, ty;
		tx = x;
		while (tx > 0)
		{
			ty = y;
			while (ty > 0)
			{
				sum += data[tx][ty];
				ty -= lowbit(ty);
			}
			tx -= lowbit(tx);
		}
		return sum;
	}
	int getvalue(int x, int y) //get value for x,y
	{
		return (getsum(x, y) - getsum(x - 1, y) - getsum(x, y - 1) + getsum(x - 1, y - 1));
	}

private:
	int data[SIZE][SIZE];
	int sizex;
	int sizey;	
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
	
};

t_TreeList2D matrix;

int main()
{
	int ti, tn;
	scanf("%d", &tn);
	for (ti = 1; ti <= tn; ++ti)
	{
		int n, t;
		scanf("%d%d", &n, &t);
		matrix.init(n, n);
		for (int i = 1; i <= t; ++i)
		{
			char inp[10];
			int x1, y1, x2, y2;
			scanf("%s", inp);
			if (inp[0] == 'Q')
			{
				scanf("%d%d", &x1, &y1);
				printf("%d\n", (matrix.getsum(x1, y1) & 1));
			}
			else
			{
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				matrix.add(x1, y1, 1);
				matrix.add(x2 + 1, y1, -1);
				matrix.add(x1, y2 + 1, -1);
				matrix.add(x2 + 1, y2 + 1, 1);
			}
		}
	}
	return 0;
}
