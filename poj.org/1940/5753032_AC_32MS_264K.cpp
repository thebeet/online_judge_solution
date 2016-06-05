/*
 * PKU1939::Diplomatic_License.cpp
 *
 *  Created on: Aug 25, 2009 8:04:32 PM
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

using namespace std;

double xx[655360];
double yy[655360];

int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " ";
		double x0(0.0), y0(0.0);
		for (int i = 0; i < n; ++i)
		{
			cin >> xx[i] >> yy[i];
			if (i & 1)
			{
				x0 -= xx[i];
				y0 -= yy[i];
			}
			else
			{
				x0 += xx[i];
				y0 += yy[i];
			}
		}
		printf("%.6lf %.6lf ", x0, y0);
		for (int i = 0; i < n - 1; ++i)
		{
			x0 = xx[i] + xx[i] - x0;
			y0 = yy[i] + yy[i] - y0;
			printf("%.6lf %.6lf ", x0, y0);
		}
		printf("\n");
	}
	return 0;
}
