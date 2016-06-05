/*
 * PKU3744::Scout_YYF_I.cpp
 *
 *  Created on: Aug 23, 2009 12:26:10 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

double p;

double f(int len)
{
	if (len < 0)
	{
		return 1.0;
	}
	if (len == 0)
	{
		return 0.0;
	}
	double pp = pow(p, (double)len);
	if (len & 1)
	{
		pp = 1 + pp;
	}
	else
	{
		pp = 1 - pp;
	}
	return p * pp / (1 + p);
}

int main()
{
	int n;
	while (cin >> n)
	{
		cin >> p;
		vector<int> arr(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		int st(1);
		if (arr[0] == 1)
		{
			printf("%.7lf\n", 0.0);
			continue;
		}
		double safe(1.0);
		p = 1 - p;
		for (int i = 0; i < n; ++i)
		{
			safe *= f(arr[i] - st);
			st = arr[i] + 1;
		}
		printf("%.7lf\n", safe);
	}
	return 0;
}
