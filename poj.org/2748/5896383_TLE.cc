/*
 * Logs_Stacking.cpp
 *
 *  Created on: Sep 22, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int ans[1000100];

int main()
{
	ans[0] = 1;
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 5;
	int m;
	for (int i = 4; ; ++i)
	{
		ans[i] = ans[i - 1] * 3 - ans[i - 2];
		((ans[i] %= 100000) += 100000) %= 100000;
		if ((ans[i] == 1) && (ans[i - 1] == 1))
		{
			m = i - 1;
			break;
		}
	}
	int tn;
	scanf("%d", &tn);

	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		n %= m;
		printf("%d\n", ans[n]);
	}
	return 0;
}
