/*
 * Big_Brother.cpp
 *
 *  Created on: Aug 17, 2008
 *      Author: yonghu
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int k, m;
		scanf("%d%d", &k, &m);
		if (k < m)
		{
			printf("0\n");
			continue;
		}
		double ans(1.0);
		for (int j = k; j > k - m; --j)
		{
			ans *= ((double)j / (double)(k + 1));
		}
		printf("%.8lf\n", ans);
	}
	return 0;
}
