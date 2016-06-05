/*
 * PKU3579::Median.cpp
 *
 *  Created on: Oct 10, 2008 1:35:02 PM
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

int x[100010];
int n;
long long n2;

bool check(const int m)
{
	long long sum(0);
	for (int i = 0; i < n; ++i)
	{
		int lo(i);
		int hi(n);
		while (lo + 1 < hi)
		{
			int mid((lo + hi) >> 1);
			((x[mid] > x[i] + m) ? hi : lo) = mid;
		}
		sum += (long long)(lo - i);
	}
	return (sum <= n2);
}

int main()
{
	while (cin >> n)
	{
		n2 = ((long long)n * (long long)(n - 1) / 2LL - 1) / 2LL;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &x[i]);
		}
		sort(x, x + n);
		int lo(0), hi(x[n - 1] - x[0]);
		while (lo + 1 < hi)
		{
			int mid((lo + hi) / 2);
			(check(mid) ? lo : hi) = mid;
		}
		cout << hi << endl;
	}
	return 0;
}



