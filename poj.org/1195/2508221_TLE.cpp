#include <stdio.h>
#include <string.h>

#define SIZE 2048

class t_TreeList2D
{
public:
	t_TreeList2D()
	{
	}
	void init(int newx, int newy)
	{
		//memset(data, 0, sizeof(data));
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
	int op;
	while (scanf("%d", &op))
	{
		switch (op)
		{
			case 0:
			{
				int s;
				scanf("%d", &s);
				matrix.init(s, s);
				break;
			}
			case 1:
			{
				int x, y, data;
				scanf("%d%d%d", &x, &y, &data);
				matrix.add(x, y, data);
				break;
			}
			case 2:
			{
				int x1, y1, x2, y2;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				printf("%d\n", matrix.getsum(x2, y2) + matrix.getsum(x1 - 1, y1 - 1) - matrix.getsum(x1 - 1, y2) - matrix.getsum(x2, y1 - 1));
				break;
			}
			default:
			{
				return 0;
			}
		}
	}
	return 0;
}
