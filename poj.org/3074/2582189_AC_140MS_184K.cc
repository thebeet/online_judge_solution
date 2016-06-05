#include <cstdio>
#include <cstring>

const int size = 9;

int assign[512];

void init_assign()
{
	int i, j;
	memset(assign, 0, sizeof(assign));
	for (i = 0; i < size; ++i)
	{
		assign[1 << i] = i;
		for (j = i + 1; j < size; ++j)
		{
			assign[(1 << i) | (1 << j)] = (i << 4) + j;
		}
	}
}

class t_Sudoku
{
public:
	void init()
	{
		int i, j;
		short t_fill = 0x1FF9; //1111111111001
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				map[i][j] = t_fill;
			}
			rect[i] = row[i] = clm[i] = 0x01FF;
		}
		complete = 0;
	}
	
	bool add(int x, int y, int data)
	{
		int tx, ty;
		map[x][y] = data;
		++complete;
		
		if (((row[x] & (1 << data)) == 0) || 
			((clm[y] & (1 << data)) == 0) || 
			((rect[(x / 3) * 3 + y / 3] & (1 << data)) == 0))
		{
			return false;
		}

		row[x] ^= 1 << data;
		clm[y] ^= 1 << data;
		rect[(x / 3) * 3 + y / 3] ^= 1 << data;
		
		for (tx = 0, ty = y; tx < size; ++tx)
		{
			if (over(tx, ty, data) == false)
			{
				return false;
			}
		}
		
		for (tx = x, ty = 0; ty < size; ++ty)
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
		
		return searchonly();
	}
	
	bool searchonly(void)
	{
		int k, x, y, rt;
		for (k = 0; k < size; ++k)
		{
			//row
			for (x = 0; x < size; ++x)
			{
				if (row[x] & (1 << k))
				{
					int py = -1;
					for (y = 0; y < size; ++y)
					{
						if (map[x][y] & (16 << k))
						{
							if (py == -1)
							{
								py = y;
							}
							else
							{
								py = -2;
								break;
							}
						}
					}
					if (py == -1)
					{
						return false;
					}
					if (py >= 0)
					{
						if (add(x, py, k) == false)
						{
							return false;
						}
					}
				}
			}
			//clm
			for (y = 0; y < size; ++y)
			{
				if (clm[y] & (1 << k))
				{
					int px = -1;
					for (x = 0; x < size; ++x)
					{
						if (map[x][y] & (16 << k))
						{
							if (px == -1)
							{
								px = x;
							}
							else
							{
								px = -2;
								break;
							}
						}
					}
					if (px == -1)
					{
						return false;
					}
					if (px >= 0)
					{
						if (add(px, y, k) == false)
						{
							return false;
						}
					}
				}
			}
			//clm
			for (rt = 0; rt < size; ++rt)
			{
				if (rect[rt] & (1 << k))
				{
					int px = -1;
					int py = -1;
					int rx = (rt / 3) * 3 + 3;
					int ry = (rt % 3) * 3 + 3;
					for (x = (rt / 3) * 3; x < rx; ++x)
					{
						for (y = (rt % 3) * 3; y < ry; ++y)
						{
							if (map[x][y] & (16 << k))
							{
								if (px == -1)
								{
									px = x;
									py = y;
								}
								else
								{
									px = -2;
									break;
								}
							}
						}
					}
					if (px == -1)
					{
						return false;
					}
					if (px >= 0)
					{
						if (add(px, py, k) == false)
						{
							return false;
						}
					}
				}
			}
			
		}
		return true;
	}
	
	bool over(int tx, int ty, int data)
	{
		if ((map[tx][ty] >= 10) && (map[tx][ty] & (16 << data)))
		{
			map[tx][ty] ^= (16 << data);
			--map[tx][ty];
			if ((map[tx][ty] & 15) == 1)
			{
				if (add(tx, ty, assign[map[tx][ty] >> 4]) == false)
				{
					return false;
				}
			}
			else if ((map[tx][ty] & 15) == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	bool findempty(int x, int y)
	{
		for ( ; ; ++x)
		{
			for ( ; y < size; ++y)
			{
				if (map[x][y] > 10)
				{
					break;
				}
			}
			if (y < size)
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
	
	bool tryfill(int x, int y)
	{
		int i;
		t_Sudoku sudoku_try;
		for (i = 0; i < size; ++i)
		{
			if (map[x][y] & (16 << i))
			{
				sudoku_try = *this;
				if (sudoku_try.add(x, y, i))
				{
					if ((sudoku_try.complete == 81) || (sudoku_try.findempty(x, y + 1)))
					{
						(*this) = sudoku_try;
						return true;
					}
				}
			}
		}
		return false;
	}
	
	void out(void)
	{
		int tx, ty;
		for (tx = 0; tx < 9; ++tx)
		{
			for (ty = 0; ty < 9; ++ty)
			{
				if (map[tx][ty] < 10)
				{
					printf("%c", map[tx][ty] + '1');
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
	short map[size][size];
	short row[size];
	short clm[size];
	short rect[size];
};

t_Sudoku sudoku;

int main()
{
	char inp[128];
	init_assign();
	for ( ; ; )
	{
		scanf("%s", inp);
		if (inp[0] == 'e')
		{
			return 0;
		}
		int i, j;
		//for (int k = 1; k <= 1000; ++k){
		sudoku.init();
		for (i = 0; i < 9; ++i)
		{
			for (j = 0; j < 9; ++j)
			{
				if (inp[i * 9 + j] != '.')
				{
					sudoku.add(i, j, inp[i * 9 + j] - '1');
				}
			}
		}
		if (sudoku.complete < 81)
		{
			sudoku.findempty(0, 0);
		}
		//}
		sudoku.out();
	}
}
