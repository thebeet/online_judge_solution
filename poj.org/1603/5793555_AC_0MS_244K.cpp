/*
 * Risk.cpp
 *
 *  Created on: 2009-9-1
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>

using namespace std;

int mat[32][32];

int main()
{
	int n;
	int ti(0);
	while (cin >> n)
	{
		memset(mat, 1, sizeof(mat));
		cout << "Test Set #" << ++ti << endl;
		for (int i = 1; i <= 19; ++i)
		{
			if (i > 1)
			{
				cin >> n;
			}
			for (int j = 0; j < n; ++j)
			{
				int m;
				cin >> m;
				mat[i][m] = 1;
				mat[m][i] = 1;
			}
		}
		for (int k = 1; k <= 20; ++k)
		{
			mat[k][k] = 0;
			for (int i = 1; i <= 20; ++i)
			{
				for (int j = 1; j <= 20; ++j)
				{
					mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
				}
			}
		}
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			cout << a << " to " << b << ": " << mat[a][b] << endl;
		}
		cout << endl;
	}
	return 0;
}
