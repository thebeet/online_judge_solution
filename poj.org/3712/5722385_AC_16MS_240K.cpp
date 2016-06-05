/*
 * PKU3712::Edges_and_More_Edges.cpp
 *
 *  Created on: Aug 22, 2009 1:49:34 PM
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
	int n, k;
	while (cin >> n >> k, n > 0)
	{
		int sum = n * (n - 1) / 2;
		if (k + k > n)
		{
			cout << sum << endl;
			continue;
		}
		int s1(0);
		for (int i = 1; i < k; ++i)
		{
			s1 += (n - i);
		}
		int m = k + k - 1;
		int s2 = m * (m - 1) / 2;
		cout << max(s1, s2) << endl;
	}
	return 0;
}
