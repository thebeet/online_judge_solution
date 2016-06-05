/*
 * PKU3587::The_Biggest_Cake.cpp
 *
 *  Created on: Oct 13, 2008 4:36:06 PM
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
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

pair<double, double> points[1024];

const double pi = acos(0.0) * 2;

double diss[1024][1024];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		cin >> n;
		double ans(0.0);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &points[i].first, &points[i].second);
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				diss[i][j] = sqrt((points[j].first - points[i].first) * (points[j].first - points[i].first) +
							(points[j].second - points[i].second) * (points[j].second - points[i].second));
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k < n; ++k)
				{
					double sinarg = abs(((points[j].first - points[i].first) * (points[k].second - points[i].second) - (points[j].second - points[i].second) * (points[k].first - points[i].first)) / (diss[i][j] * diss[i][k]));
					double r = diss[j][k] / sinarg / 2.0;
					ans = max(ans, r);
				}
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}



