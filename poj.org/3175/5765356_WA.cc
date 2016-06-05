/*
 * PKU3175::Finding_Bovine_Roots.cpp
 *
 *  Created on: Oct 7, 2008 11:05:36 AM
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
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int len;
	long long z1, z2;
	long long s1, s2;
	double d1, d2;
	double ds1, ds2;
	cin >> len >> z1;
	if (z1 == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	z2 = z1 + 1;
	s1 = z1 * z1;
	s2 = z2 * z2;
	d1 = z1;
	d2 = z2;
	ds1 = s1;
	ds2 = s2;
	for (int i = 0; i < len; ++i)
	{
		d1 /= 10.0;
		d2 /= 10.0;
		ds1 /= 100.0;
		ds2 /= 100.0;
	}
	for (int i = 0; ; ++i)
	{
		if ((int)(i * 2 * d1 + ds1) < (int)(i * 2 * d2 + ds2))
		{
			cout << (long long)((i + d1) * (i + d1)) + 1LL << endl;
			return 0;
		}
	}
	return 0;
}
