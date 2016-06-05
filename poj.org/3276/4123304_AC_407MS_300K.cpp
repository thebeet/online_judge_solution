/*
 * PKU3276::Face_The_Right_Way.cpp
 *
 *  Created on: Sep 24, 2008 9:24:24 PM
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
	int i, n;
	cin >> n;
	char toward[5010];
	char towardbak[5010];
	for (i = 0; i < n; ++i)
	{
		cin >> towardbak[i];
	}
	int ansk, ansm;
	ansm = 100000;
	int k, m;
	for (k = 1; k <= n; ++k)
	{
		m = 0;
		memcpy(toward, towardbak, 5010);
		for (i = 0; i <= n - k; ++i)
		{
			if (toward[i] == 'B')
			{
				++m;
				int j;
				for (j = 0; j < k; ++j, ++i)
				{
					if (toward[i] == 'F')
					{
						break;
					}
				}
				if (j < k)
				{
					++m;
					int t(i + k);
					if (t > n) break;
					for (int h = 1; h <= j; ++h)
					{
						toward[t - h] = (toward[t - h] == 'B') ? 'F' : 'B';
					}
				}
				--i;
			}
		}
		if (i <= n - k) continue;
		for ( ; i < n; ++i)
		{
			if (toward[i] == 'B') break;
		}
		if (i < n) continue;
		if (ansm > m)
		{
			ansk = k;
			ansm = m;
		}
	}
	cout << ansk << " " << ansm << endl;
	return 0;
}
