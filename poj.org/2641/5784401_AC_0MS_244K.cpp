/*
 * Billiard.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(0.0) * 2.0;

int main()
{
	int a, b, s, m, n;
	while ((cin >> a >> b >> s >> m >> n), a > 0)
	{
		a *= m;
		b *= n;
		double c = sqrt((double)a * (double)a + (double)b * (double)b);
		printf("%.2lf %.2lf\n", atan2((double)b, (double)a) / pi * 180.0, c / s);
	}
	return 0;
}
