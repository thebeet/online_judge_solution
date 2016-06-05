/*
 * Wavelet_Compression.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */
#include <iostream>
#include <algorithm>

using namespace std;

int list[2][1024];

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int i;
		for (i = 0; i < n; ++i)
		{
			cin >> list[0][i];
			list[1][i] = list[0][i];
		}
		int p0 = 0;
		int p1 = 1;
		for (i = 1; i < n; i <<= 1)
		{
			for (int j = 0; j < i; ++j)
			{
				list[p1][j * 2] = (list[p0][j] + list[p0][j + i]) / 2;
				list[p1][j * 2 + 1] = (list[p0][j] - list[p0][j + i]) / 2;
			}
			swap(p0, p1);
		}
		for (i = 0; i < n; ++i)
		{
			cout << list[p0][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
