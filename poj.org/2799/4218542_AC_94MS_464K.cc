/*
 * PKU2799::IP_Networks.cpp
 *
 *  Created on: Oct 8, 2008 8:33:39 PM
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

unsigned int ip[1024];

int main()
{
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		unsigned int a, b, c, d;
		scanf("%u.%u.%u.%u", &a, &b, &c, &d);
		ip[i] = (a << 24) | (b << 16) | (c << 8) | d;
	}
	int k;
	for (k = 31; k >= 0; --k)
	{
		unsigned int d(ip[0] & (1 << k));
		int i;
		for (i = 1; i < m; ++i)
		{
			if ((ip[i] & (1 << k)) != d)
			{
				break;
			}
		}
		if (i < m) break;
	}
	if (k == 31)
	{
		cout << "0.0.0.0" << endl;
		cout << "0.0.0.0" << endl;
	}
	else
	{
		unsigned int mask = ~((1 << (k + 1)) - 1);
		ip[0] &= mask;
		cout << (ip[0] >> 24) << '.' << ((ip[0] >> 16) & 0xff) << '.' << ((ip[0] >> 8) & 0xff) << '.' << (ip[0] & 0xff) << endl;
		cout << (mask >> 24) << '.' << ((mask >> 16) & 0xff) << '.' << ((mask >> 8) & 0xff) << '.' << (mask & 0xff) << endl;
	}
	return 0;
}

