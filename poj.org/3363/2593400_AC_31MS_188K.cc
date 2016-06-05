#include <cstdio>
#include <cstring>

const int SIZE = 128;

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
	void add(int x, int y)
	{
		int tx, ty;
		tx = x;
		while (tx <= sizex)
		{
			ty = y;
			while (ty <= sizey)
			{
				data[tx][ty] ^= 1;
				ty += lowbit(ty);
			}
			tx += lowbit(tx);
		}
	}
	char getsum(int x, int y) //get sum for 1,1 to x,y
	{
		char sum = '0';
		int tx, ty;
		tx = x;
		while (tx > 0)
		{
			ty = y;
			while (ty > 0)
			{
				sum ^= data[tx][ty];
				ty -= lowbit(ty);
			}
			tx -= lowbit(tx);
		}
		return sum;
	}

private:
	char data[SIZE][SIZE];
	int sizex;
	int sizey;	
	int lowbit(const int x)
	{
		return (x & (x ^ (x - 1)));
	}
	
};

t_TreeList2D tmap;
char buf[128];

int main()
{
	int r, n, c, m;
	while (scanf("%d%d%d%d", &n, &m, &r, &c), r > 0)
	{
		int i, j;
		int ans = 0;
		tmap.init(n + 1, m + 1);
		for (i = 1; i <= n; ++i)
		{
			scanf("%s", buf + 1);
			for (j = 1; j <= m; ++j)
			{
				if (tmap.getsum(i, j) != buf[j])
				{
					if ((i + r - 1 > n) || (j + c - 1 > m))
					{
						ans = -1;
						break;
					}
					tmap.add(i, j);
					tmap.add(i + r, j);
					tmap.add(i, j + c);
					tmap.add(i + r, j + c);
					++ans;
				}
			}
			if (j <= m)
			{
				break;
			}
		}
		for ( ++i; i <= n; ++i)
		{
			scanf("%*s");
		}
		printf("%d\n", ans);
	}
	return 0;
}
