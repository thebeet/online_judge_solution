#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int wid = 4;
const int size = wid * wid;
const int completesize = size * size;

int binindex[65536];
int rect_x[16][16];
int rect_y[16][16];

void init_index()
{
	int i, j;
	memset(binindex, 0, sizeof(binindex));
	for (i = 0; i < size; ++i)
	{
		binindex[1 << i] = i;
		for (j = 0; j < size; ++j)
		{
			if (i != j)
			{
				binindex[(1 << i) | (1 << j)] = (i << 4) + j;
			}
			rect_x[i][j] = (i / wid) * wid + (j / wid);
			rect_y[i][j] = (i % wid) * wid + (j % wid);
		}
	}
}

class t_Sudoku
{
public:
	void init()
	{
		int i, j;
		for (i = 0; i < size; ++i)
		{
			for (j = 0; j < size; ++j)
			{
				rect[i][j] = row[i][j] = clm[i][j] = map[i][j] = 0x10FFFF; //1111111111111111
			}
		}
		complete = 0;
	}
	
	bool add(int x, int y, int data)
	{
		int t;
		if (map[x][y] < 0xFFFF)
		{
			return (map[x][y] == data);
		}
		if (row[x][data] < 0xFFFF)
		{
			return (row[x][data] == y);
		}
		if (clm[y][data] < 0xFFFF)
		{
			return (clm[y][data] == x);
		}
		int br = rect_x[x][y];
		int bm = rect_y[x][y];
		if (rect[br][data] < 0xFFFF)
		{
			return (rect[br][data] == bm);
		}
		map[x][y] = data;
		++complete;
		row[x][data] = y;
		clm[y][data] = x;
		rect[br][data] = bm;
		
		for (t = 0; t < size; ++t)
		{
			if (t != x)
			{
				if (overcell(t, y, data) == false)
				{
					return false;
				}
			}
			if (t != y)
			{
				if (overcell(x, t, data) == false)
				{
					return false;
				}
			}
			int rx = rect_x[br][t];
			int ry = rect_y[br][t];
			if ((rx != x) || (ry != y))
			{
				if (overcell(rx, ry, data) == false)
				{
					return false;
				}
			}
		}
		
		for (t = 0; t < size; ++t)
		{
			if (t != data)
			{
				if ((over(row, x, t, y, 2) && over(clm, y, t, x, 3) && over(rect, br, t, bm, 4)) == false)
				{
					return false;
				}
			}
		}
		
		return true;
	}
	
	bool overcell(int tx, int ty, int data)
	{
		return (over(map, tx, ty, data, 1) &&
				over(row, tx, data, ty, 2) &&
				over(clm, ty, data, tx, 3) &&
				over(rect, rect_x[tx][ty], data, rect_y[tx][ty], 4));
	}
	
	bool dupcut(int map[][16], int x, int y, int mode)
	{
		int t, j;
		int d1, d2;
		for (t = 0; t < size; ++t)
		{
			if (t != x)
			{
				if (map[t][y] == map[x][y])
				{
					d1 = binindex[map[x][y] & 0xFFFF] & 0xF;
					d2 = binindex[map[x][y] & 0xFFFF] >> 4;
					for (j = 0; j < size; ++j)
					{
						if ((j != t) && (j != x))
						{
							switch (mode)
							{
							case 1:
								if ((overcell(j, y, d1) && overcell(j, y, d2)) == false)
								{
									return false;
								}
								break;
							case 2:
								if ((overcell(j, d1, y) && overcell(j, d2, y)) == false)
								{
									return false;
								}
								break;
							case 3:
								if ((overcell(d1, j, y) && overcell(d2, j, y)) == false)
								{
									return false;
								}
							}
						}
					}
				}
			}
			if (t != y)
			{
				if (map[x][t] == map[x][y])
				{
					d1 = binindex[map[x][y] & 0xFFFF] & 0xF;
					d2 = binindex[map[x][y] & 0xFFFF] >> 4;
					for (j = 0; j < size; ++j)
					{
						if ((j != t) && (j != y))
						{
							switch (mode)
							{
							case 1:
								if ((overcell(x, j, d1) && overcell(x, j, d2)) == false)
								{
									return false;
								}
								break;
							case 2:
								if ((overcell(x, d1, j) && overcell(x, d2, j)) == false)
								{
									return false;
								}
								break;
							case 3:
								if ((overcell(d1, x, j) && overcell(d2, x, j)) == false)
								{
									return false;
								}
								break;
							case 4:
								if ((overcell(rect_x[x][d1], rect_y[x][d1], j) && overcell(rect_x[x][d2], rect_y[x][d2], j)) == false)
								{
									return false;
								}
							}
						}
					}
				}
			}
		}
		return true;
	}
	
	bool over(int map[][16], int tx, int ty, int data, int mode)
	{
		if (map[tx][ty] > 0xFFFF)
		{
			if ((map[tx][ty] & (1 << data)) > 0)
			{
				map[tx][ty] ^= (1 << data);
				map[tx][ty] -= 0x10000;
				if ((map[tx][ty] >> 16) == 2)
				{
					if (dupcut(map, tx, ty, mode) == false)
					{
						return false;
					}
					return true;
				}
				else if ((map[tx][ty] >> 16) == 1)
				{
					switch (mode)
					{
					case 1:
						return add(tx, ty, binindex[map[tx][ty] & 0xFFFF]);
					case 2:
						return add(tx, binindex[map[tx][ty] & 0xFFFF], ty);
					case 3:
						return add(binindex[map[tx][ty] & 0xFFFF], tx, ty);
					case 4:
						int pos = binindex[rect[tx][ty] & 0xFFFF];
						return add(rect_x[tx][pos], rect_y[tx][pos], ty);
					}
					return true;
				}
				else 
				{
					return ((map[tx][ty] >> 16) > 0);
				}
			}
			return true;
		}
		else
		{
			return (map[tx][ty] != data);
		}
	}
	
	bool findempty(int x, int y)
	{
		if (complete == completesize)
		{
			return true;
		}
		for ( ; ; ++x)
		{
			for ( ; y < size; ++y)
			{
				if ((map[x][y] >> 16) > 1)
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
			if ((map[x][y] & (1 << i)) > 0)
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
				if (map[tx][ty] < 0xFFFF)
				{
					printf("%c", map[tx][ty] + 'A');
				}
				else
				{
					printf("-");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	int complete;
	int map[size][size];
	int row[size][size];
	int clm[size][size];
	int rect[size][size];
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
				return 0;
			}
			for (j = 0; j < size; ++j)
			{
				if (inp[j] != '-')
				{
					/*if (*/sudoku.add(i, j, inp[j] - 'A');/* == false)
					{
						printf("%d %d error\n", i, j);
					}*/
				}
			}
		}
		//cout << sudoku.complete << endl;
		//sudoku.out();
		if (sudoku.findempty(0, 0) == false)
		{
			printf("Error\n");
		}
		sudoku.out();
	}
	return 0;
}
/*
--A----C-----O-I
-J--A-B-P-CGF-H-
--D--F-I-E----P-
-G-EL-H----M-J--
----E----C--G---
-I--K-GA-B---E-J
D-GP--J-F----A--
-E---C-B--DP--O-
E--F-M--D--L-K-A
-C--------O-I-L-
H-P-C--F-A--B---
---G-OD---J----H
K---J----H-A-P-L
--B--P--E--K--A-
-H--B--K--FI-C--
--F---C--D--H-N-

--A--JEC---D-O-I
-J--A-B-P-CGF-HE
--D--F-I-E----P-
-G-EL-H----M-J--
----E----C--G---
-I--K-GA-B--PE-J
D-GP--J-F----A--
-E--FC-B--DP--O-
E--F-M-JD--L-K-A
-C---BAE--OFI-LP
H-P-C--F-A--B-J-
---G-OD---JC---H
K---J---CH-A-P-L
--B-DP-HE--K--A-
-H--BA-K--FI-C--
--F--EC--D--H-NK


FPAHMJECNLBDKOGI
OJMIANBDPKCGFLHE
LNDKGFOIJEAHMBPC
BGCELKHPOFIMAJDN
MFHBELPOACKJGNID
CILNKDGAHBMOPEFJ
DOGPIHJMFNLECAKB
JEKAFCNBGIDPLHOM
EBOFPMIJDGHLNKCA
NCJDHBAEKMOFIGLP
HMPLCGKFIAENBDJO
AKIGNODLBPJCEFMH
KDEMJIFNCHGAOPBL
GLBCDPMHEONKJIAF
PHNOBALKMJFIDCEG
IAFJOECGLDPBHMNK
*/
