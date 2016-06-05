#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int N = 4;

class Mask
{
public:
	void spin()
	{
		char tmp[N][N];
		memcpy(tmp, board, sizeof(tmp));
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				board[i][j] = tmp[N - 1 - j][i]; 
			}
		}
	}

	void input()
	{
		char buff[N + 2];
		for (int i = 0; i < N; ++i)
		{
			cin >> buff;
			memcpy(board[i], buff, sizeof(char) * N);
		}
	}

	void getAlive(pair<int, int> alive[]) const
	{
		int k = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (board[i][j] == 'X')
				{
					alive[k++] = make_pair(i, j);
				}
			}
		}
	}
private:
       	char board[N][N];
};

class Board
{
public:
	void input()
	{
		char buff[N + 2];
		for (int i = 0; i < N; ++i)
		{
			cin >> buff;
			memcpy(board[i], buff, sizeof(char) * N);
		}
	}
	void output(const Mask &mask)
	{
		pair<int, int> alive[N];
		mask.getAlive(alive);
		for (int i = 0; i < N; ++i)
		{
			cout << board[alive[i].first][alive[i].second];
		}
	}
private:
       	char board[N][N];
};

int main()
{
	Board board;
	Mask mask;
	mask.input();
	board.input();
	for (int i = 0; i < 4; ++i)
	{
		board.output(mask);
		mask.spin();
	}
	cout << endl;
	return 0;
}
