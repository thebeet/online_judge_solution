/*
 * PKU3685::Matrix.cpp
 *
 *  Created on: Aug 31, 2008 1:33:22 PM
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
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		long long i, j, n, m;
		cin >> n >> m;
		--m;
		long long slo(-1000000000000000LL), shi(1000000000000000LL);
		long long nl(-n + 1);
		while (slo + 1LL < shi)
		{
			long long smid((slo + shi) >> 1);
			long long ssum(0);
			for (long long si = nl; si < n; ++si)
			{
				long long lo(-1), hi(n - abs(si));
				while (lo + 1LL < hi)
				{
					long long mid((lo + hi) >> 1);
					long long i, j;
					if (si < 0)
					{
						i = mid + 1;
						j = i - si;
					}
					else
					{
						j = mid + 1;
						i = j + si;
					}
					long long value = i * i + j * j + 100000LL * si + i * j;
					((value > smid) ? hi : lo) = mid;
				}
				ssum += hi;
			}
			((ssum > m) ? shi : slo) = smid;
		}
		cout << shi << endl;
	}
	return 0;
}
