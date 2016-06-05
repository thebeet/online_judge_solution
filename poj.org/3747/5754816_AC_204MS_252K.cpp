/*
 * Scout_YYF_II.cpp
 *
 *  Created on: 2009-8-26
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double pi = acos(0.0) * 2;
const double esp = 1e-10;
double xxs[16];
double yys[16];

int main()
{
	int n, r;
	while (cin >> n >> r)
	{
		double x0, y0;
		cin >> x0 >> y0;
		for (int i = 0; i < n; ++i)
		{
			cin >> xxs[i] >> yys[i];
		}
		bool flag(false);
		for (int i = 0; i < 200001; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				double xxx = cos(pi * double(i) / 400000.0) * r;
				if (j & 1) xxx = -xxx;
				double yyy = sin(pi * double(i) / 400000.0) * r;
				if (j & 2) yyy = -yyy;
				double dis = (xxx - x0) * (xxx - x0) + (yyy - y0) * (yyy - y0);
				int k;
				for (k = 0; k < n; ++k)
				{
					double db = (xxx - xxs[k]) * (xxx - xxs[k]) + (yyy - yys[k]) * (yyy - yys[k]);
					if (dis >= db)
					{
						break;
					}
				}
				if (k == n)
				{
					flag = true;
					break;
				}
			}
		}
		cout << ((flag) ? "Yes" : "No") << endl;
	}

	return 0;
}
