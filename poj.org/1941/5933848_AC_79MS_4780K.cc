/*
 * The_Sierpinski_Fractal.cpp
 *
 *  Created on: Sep 29, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int C[1024][1024];

int main()
{
	C[0][0] = 1;
	for (int i = 1; i < 1024; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) & 1;
		}
		C[i][i] = 1;
	}

	int n;
	while ((cin >> n), n > 0)
	{
		int N = 1 << n;
		for (int i = 0; i < N; ++i)
		{
			if (N - (i & 0x7ffffffe) - 2 > 0)
			{
				cout << string(N - (i & 0x7ffffffe) - 2 , ' ');
			}
			for (int j = 0; j <= (i / 2); ++j)
			{
				bool flag =  ((C[i / 2][j] & 1) == 1);
				if (flag)
				{
					if ((i & 1) == 0)
					{
						cout << " /\\ ";
					}
					else
					{
						cout << "/__\\";
					}
				}
				else
				{
					if ((i & 1) == 0)
					{
						cout << "    ";
					}
					else
					{
						cout << "    ";
					}
				}
			}
			cout << endl;
		}
		cout << endl;
	}


	return 0;
}
