/*
 * Factstone_Benchmark.cpp
 *
 *  Created on: Sep 25, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int ans[1024];

int main()
{
	int n;
	double d(1.0);
	int k(0);
	int t(2);
	for (int i = 0; i < 21; ++i)
	{
		int j((1 << (i + 1)) + t);
		while (j >= 0)
		{
			++k;
			d *= k;
			while (d >= 1.0)
			{
				d /= 2.0;
				--j;
			}
		}
		t = j;
		ans[i] = k - 1;
	}
	while ((cin >> n), n > 0)
	{
		cout << ans[(n - 1960) / 10] << endl;
	}
	return 0;
}
