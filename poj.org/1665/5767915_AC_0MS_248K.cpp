/*
 * PKU1665::Biker_s_Trip_Odometer.cpp
 *
 *  Created on: Aug 27, 2009 10:38:11 PM
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

const double pi = 3.1415927;

int main()
{
	double diameter;
	int revolutions;
	double tim;
	int ti(0);
	while ((cin >> diameter >> revolutions >> tim), revolutions > 0)
	{
		cout << "Trip #" << ++ti << ": ";
		double dis = diameter * pi * revolutions / 5280.0 / 12;
		printf("%.2lf %.2lf\n", dis, dis / tim * 3600);
	}
	return 0;
}
