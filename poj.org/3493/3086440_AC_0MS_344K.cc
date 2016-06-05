#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int i, j, n, m, sum;
	int puzzle[32][32];
	memset(puzzle, 0, sizeof(puzzle));
	sum = 0;
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= m; ++j)
		{
			cin >> puzzle[i][j];
			if (puzzle[i][j] * puzzle[i - 1][j] > 0) sum += puzzle[i][j] * puzzle[i - 1][j];
			if (puzzle[i][j] * puzzle[i][j - 1] > 0) sum += puzzle[i][j] * puzzle[i][j - 1];
		}
	}
	cout << sum << endl;
	return 0;
}
