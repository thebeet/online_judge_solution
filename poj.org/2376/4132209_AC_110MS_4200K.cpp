/*
 * PKU2376::Cleaning_Shifts.cpp
 *
 *  Created on: Sep 26, 2008 3:59:48 PM
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

int shf[1024*1024];

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		shf[a] = max(shf[a], b);
	}
	int ans(0);
	int st(1);
	int ed(1);
	for ( ; ed <= t; )
	{
		int mx(0);
		for (int j = st; j <= ed; ++j)
		{
			mx = max(mx, shf[j]);
		}
		if (mx < ed)
		{
			cout << -1 << endl;
			return 0;
		}
		st = ed + 1;
		ed = mx + 1;
		++ans;
	}
	cout << ans << endl;
	return 0;
}
