/*
 * Integer_Approximation.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double a;
	int l;
	cin >> a >> l;
	int an(0), ad(1);
	double ap(a);
	for (int i = 1; i <= l; ++i)
	{
		int d = i;
		int nl = (int)(d * a);
		int nh = nl + 1;
		if (nl >= l)
		{
			nl = l;
		}
		if (nl == 0)
		{
			nl = 1;
		}
		if (nh >= l)
		{
			nh = l;
		}
		double pl = fabs((double)nl / d - a);
		if (pl < ap)
		{
			an = nl;
			ad = d;
			ap = pl;
		}
		double ph = fabs((double)nh / d - a);
		if (ph < ap)
		{
			an = nh;
			ad = d;
			ap = ph;
		}
	}
	cout << an << " " << ad << endl;
	return 0;
}
