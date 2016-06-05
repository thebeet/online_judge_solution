/*
 * Ranking_the_Cows.cpp
 *
 *  Created on: 2009-9-11
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int rank[1024][1024];

int main()
{
	int n, m;
	memset(rank, 0, sizeof(rank));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int lo, hi;
		scanf("%d%d", &lo, &hi);
		--lo; --hi;
		rank[lo][hi] = 1;
		rank[hi][lo] = -1;
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			if (rank[i][k] == 0) continue;
			for (int j = 0; j < n; ++j)
			{
				if (rank[k][j] == 0) continue;
				if (rank[i][k] == rank[k][j])
				{
					rank[i][j] = rank[i][k];
				}
			}
		}
	}
	int ans(0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (rank[i][j] == 0)
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
