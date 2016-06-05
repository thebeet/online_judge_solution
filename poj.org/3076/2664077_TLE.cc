#include <cstdio>
#include <cstring>

const int wid = 4;
const int size = wid * wid;

int indexs[65536];
int rax[16];
int ray[16];

void init_index()
{
	int i, j;
	memset(indexs, 0, sizeof(indexs));
	for (i = 0; i < size; ++i)
	{
		indexs[1 << i] = i;
		rax[i] = (i / wid) * wid;
		ray[i] = (i % wid) * wid;
		for (j = i + 1; j < size; ++j)
		{
			indexs[(1 << i) | (1 << j)] = (i << 4) + j;
		}
	}
}

class t_Sudoku
{
public:
	void init()
	{
		int i, j;
		int t_fill = 0xFFFFF; //111111111111111100010000
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				map[i][j] = t_fill;
			}
			rect[i] = row[i] = clm[i] = 0xFFFF; //11111111111111111
		}
		complete = 0;
	}
	
	bool add(int x, int y, int data)
	{
		int tx, ty;
		if (map[x][y] == data) 
		{
			return true;
		}
		map[x][y] = data;
		++complete;
		
		if (((row[x] & (1 << data)) == 0) || 
			((clm[y] & (1 << data)) == 0) || 
			((rect[rax[x] + y / wid] & (1 << data)) == 0))
		{
			return false;
		}

		row[x] ^= 1 << data;
		clm[y] ^= 1 << data;
		rect[rax[x] + y / wid] ^= 1 << data;
		
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
		
		int rx = rax[x] + wid;
		int ry = rax[y] + wid;
		for (tx = rax[x]; tx < rx; ++tx)
		{
			for (ty = rax[y]; ty < ry; ++ty)
			{
				if (over(tx, ty, data) == false)
				{
					return false;
				}
			}
		}
		
		return true;
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
			
			for (rt = 0; rt < size; ++rt)
			{
				if (rect[rt] & (1 << k))
				{
					int px = -1;
					int py = -1;
					int rx = rax[rt] + wid;
					int ry = ray[rt] + wid;
					for (x = rax[rt]; x < rx; ++x)
					{
						for (y = ray[rt]; y < ry; ++y)
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
			//*/
		}
		return true;
	}
	
	bool over(int tx, int ty, int data)
	{
		if (map[tx][ty] & (16 << data))
		{
			map[tx][ty] ^= (16 << data);
			--map[tx][ty];
			if ((map[tx][ty] & 15) == 0)
			{
				if (add(tx, ty, indexs[map[tx][ty] >> 4]) == false)
				{
					return false;
				}
			}
			else if (map[tx][ty] < 0)
			{
				return false;
			}
		}
		return true;
	}
	
	bool findempty(int x, int y)
	{
		if (searchonly() == false)
		{
			return false;
		}
		if (complete == size * size)
		{
			return true;
		}
		for ( ; ; ++x)
		{
			for ( ; y < size; ++y)
			{
				if (map[x][y] > 15)
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
					if ((sudoku_try.complete == size * size) || (sudoku_try.findempty(x, y + 1)))
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
		for (tx = 0; tx < size; ++tx)
		{
			for (ty = 0; ty < size; ++ty)
			{
				printf("%c", map[tx][ty] + 'A');
			}
			printf("\n");
		}
		printf("\n");
	}
	
	int complete;
	int map[size][size];
	int row[size];
	int clm[size];
	int rect[size];
};

t_Sudoku sudoku;

int main()
{
	init_index();
	char inp[1024];
	int i, j;
	for (;;)
	{
		sudoku.init();
		for (i = 0; i < size; ++i)
		{
			if (scanf("%s", inp) == EOF)
			{
				break;
			}
			for (j = 0; j < size; ++j)
			{
				if (inp[j] != '-')
				{
					sudoku.add(i, j, inp[j] - 'A');/* == false)
					{
						printf("error\n");
					}*/
				}
			}
		}
		if (i < size)
		{
			break;
		}
		if (sudoku.complete < size * size)
		{
			sudoku.findempty(0, 0);
		}
		sudoku.out();
	}
	return 0;
}