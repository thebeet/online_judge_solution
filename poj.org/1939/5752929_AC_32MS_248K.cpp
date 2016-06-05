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

int main()
{
	int n;
	while (cin >> n)
	{
		cout << n << " ";
		double x0, y0, xt, yt;
		cin >> x0 >> y0;
		xt = x0; yt = y0;
		for (int i = 1; i < n; ++i)
		{
			double xx, yy;
			cin >> xx >> yy;
			printf("%.6lf %.6lf ",(xx + xt) / 2.0, (yy + yt) / 2.0);
			xt = xx;
			yt = yy;
		}
		printf("%.6lf %.6lf\n",(x0 + xt) / 2.0, (y0 + yt) / 2.0);
	}
	return 0;
}
