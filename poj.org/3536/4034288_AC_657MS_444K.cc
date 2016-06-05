/*
 * PKU3536::Beer_Refrigerator.cpp
 *
 *  Created on: Sep 7, 2008 4:17:45 PM
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
		int a, b, c;
		int ans, aa, ab, ac;
		ans = n * 6 + 1;
		for (a = 1; a <= n; ++a)
		{
			if ((n % a) != 0)
			{
				continue;
			}
			int tn = (n / a);
			for (b = a; b <= tn; ++b)
			{
				if ((tn % b) != 0)
				{
					continue;
				}
				c = (tn / b);
				int tans = (a * b + b * c + a * c) * 2;
				if (ans >= tans)
				{
					ans = tans;
					aa = a;
					ab = b;
					ac = c;
				}
			}
		}
		cout << aa << " " << ab << " " << ac << endl;
	}
	return 0;
}
