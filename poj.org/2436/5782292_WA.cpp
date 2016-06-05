/*
 * Disease_Management.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int cow[1024];

int n, d, k;

int dfs(const int p, const int dt, const int ds)
{
	if (dt == k)
	{
		int sum(0);
		int tds = (~ds) & 0xff;
		for (int i = 0; i < n; ++i)
		{
			if ((cow[i] & tds) == 0)
			{
				++sum;
			}
		}
		return sum;
	}
	else if (p <= d)
	{
		return max(dfs(p + 1, dt, ds), dfs(p + 1, dt + 1, ds | (1 << p)));
	}
	return 0;
}

int main()
{
	scanf("%d%d%d", &n, &d, &k);
	memset(cow, 0, sizeof(cow));
	for (int i = 0; i < n; ++i)
	{
		int dn;
		scanf("%d", &dn);
		for (int di = 0; di < dn; ++di)
		{
			int did;
			scanf("%d", &did);
			cow[i] |= (1 << did);
		}
	}
	printf("%d\n", dfs(1, 0, 0));
	return 0;
}
