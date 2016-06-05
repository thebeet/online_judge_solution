#include <stdio.h>
#include <string.h>

int seqx[128];
int seqy[128];

class t_Sudoku
{
public:
	void init() //初始化数独矩阵
	{
		memset(enb, true, sizeof(enb));
		complete = 0;
		for (int x = 0; x < 9; ++x)
		{
			for (int y = 0; y < 9; ++y)
			{
				map[x][y] = 19;
			}
		}
	}
	
	bool findempty(int x, int y) //寻找下一个空白格子
	{
		seqx[0] = 0;
		seqy[0] = 0;
		for ( ; ; ++x)
		{
			for ( ; y < 9; ++y)
			{
				if (map[x][y] > 10)
				{
					break;
				}
			}
			if (y < 9)
			{
				break;
			}
			else
			{
				y = 0;
			}
		}
		return tryfill(x, y);
	}
	
	bool tryfill(int x, int y) //
	{
		int i;
		t_Sudoku sudoku_try;
		for (i = 1; i <= 9; ++i)
		{
			if (enb[x][y][i])
			{
				seqx[0] = 0;
				seqy[0] = 0;
				sudoku_try = *this;
				if (sudoku_try.add(x, y, i))
				{
					if (sudoku_try.complete == 81)
					{
						(*this) = sudoku_try;
						return true;
					}
					else
					{
						if (sudoku_try.findempty(x, y + 1) == true)
						{
							(*this) = sudoku_try;
							return true;
						}
					}
				}
			}
		}
		return false;
	}
	
	bool add(int x, int y, int data)
	{
		int i, tx, ty;
		map[x][y] = data;
		++complete;
		for (tx = 0, ty = y; tx < 9; ++tx)
		{
			if (over(tx, ty, data) == false)
			{
				return false;
			}
		}
		for (tx = x, ty = 0; ty < 9; ++ty)
		{
			if (over(tx, ty, data) == false)
			{
				return false;
			}
		}
		int rx = (x / 3) * 3 + 3;
		int ry = (y / 3) * 3 + 3;
		for (tx = (x / 3) * 3; tx < rx; ++tx)
		{
			for (ty = (y / 3) * 3; ty < ry; ++ty)
			{
				if (over(tx, ty, data) == false)
				{
					return false;
				}
			}
		}
		if (seqx[0] < seqy[0])
		{
			tx = seqx[++seqx[0]];
			ty = seqy[seqx[0]];
			for (i = 1; ; ++i)
			{
				if (enb[tx][ty][i])
				{
					break;
				}
			}
			return add(tx, ty, i);
		}
		return true;
	}
	
	bool over(int tx, int ty, int data)
	{
		if ((map[tx][ty] >= 10) && (enb[tx][ty][data]))
		{
			enb[tx][ty][data] = false;
			--map[tx][ty];
			if (map[tx][ty] == 12)
			{
				if (findcut(tx, ty) == false)
				{
					return false;
				}
			}
			else if (map[tx][ty] == 11)
			{
				seqx[++seqy[0]] = tx;
				seqy[seqy[0]] = ty;
			}
			else if (map[tx][ty] == 10)
			{
				return false;
			}
		}
		return true;
	}
	
	bool findcut(int x, int y)
	{
		int tx, ty;
		int i, j, k;
		for (tx = 0, ty = y; tx < 9; ++tx)
		{
			if (tx == x)
			{
				continue;
			}
			if (memcmp(enb[x][y], enb[tx][ty], 10) == 0)
			{
				for (k = 1; k <= 9; ++k)
				{
					if (enb[x][y][k])
					{
						for (i = 0; i < 9; ++i)
						{
							if ((i != x) && (i != tx))
							{
								if (over(i, y, k) == false)
								{
									return false;
								}
							}
						}
					}
				}
				break;
			}
		}
		
		for (tx = x, ty = 0; ty < 9; ++ty)
		{
			if (ty == y)
			{
				continue;
			}
			if (memcmp(enb[x][y], enb[tx][ty], 10) == 0)
			{
				for (k = 1; k <= 9; ++k)
				{
					if (enb[x][y][k])
					{
						for (i = 0; i < 9; ++i)
						{
							if ((i != y) && (i != ty))
							{
								if (over(x, i, k) == false)
								{
									return false;
								}
							}
						}
					}
				}
				break;
			}
		}
		/*
		for (tx = x, ty = 0; ty < 9; ++ty)
		{
			if (over(tx, ty, data) == false)
			{
				return false;
			}
		}
		int rx = (x / 3) * 3 + 3;
		int ry = (y / 3) * 3 + 3;
		for (tx = (x / 3) * 3; tx < rx; ++tx)
		{
			for (ty = (y / 3) * 3; ty < ry; ++ty)
			{
				if (over(tx, ty, data) == false)
				{
					return false;
				}
			}
		}*/
		return true;
	}
	
	void out()
	{
		int tx, ty;
		for (tx = 0; tx < 9; ++tx)
		{
			for (ty = 0; ty < 9; ++ty)
			{
				if (map[tx][ty] < 10)
				{
					printf("%c", map[tx][ty] + '0');
				}
				else
				{
					printf(".");
				}
			}
			//printf("\n");
		}
		printf("\n");
	}
	
	int complete;
	char map[9][9];
	bool enb[9][9][10];
	
private:
};

t_Sudoku sudoku;

char inp[128];

int main()
{
	for ( ; ; )
	{
		scanf("%s", inp);
		if (inp[0] == 'e')
		{
			return 0;
		}
		int i, j;
		memset(seqx, 0, sizeof(seqx));
		memset(seqy, 0, sizeof(seqy));
		sudoku.init();
		for (i = 0; i < 9; ++i)
		{
			for (j = 0; j < 9; ++j)
			{
				if (inp[i * 9 + j] != '.')
				{
					sudoku.add(i, j, inp[i * 9 + j] - '0');
				}
			}
		}
		if (sudoku.complete < 81)
		{
			sudoku.findempty(0, 0);
		}
		sudoku.out();
	}
}
