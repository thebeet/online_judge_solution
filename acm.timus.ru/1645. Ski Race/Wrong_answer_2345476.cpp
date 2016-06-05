/*
 * Ski_Race.cpp
 *
 *  Created on: 2008-11-15
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

int rank[2048];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &rank[i]);
		int pre(0);
		int ed(0);
		for (int j = 0; j < i; ++j)
		{
			if (rank[j] < rank[i])
			{
				++pre;
			}
		}
		printf("%d %d\n", rank[i] - pre, rank[i] + ((n - i) - (rank[i] - pre)));
	}
	return 0;
}
