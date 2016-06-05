/*
 * PKU2773::Happy_2006.cpp
 *
 *  Created on: Oct 4, 2008 10:16:50 PM
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

int ans[1024 * 1024];
bool isp[1024 * 1024];

template <typename T_INT>
T_INT gcd(const T_INT &a_a, const T_INT &a_b)
{
	T_INT a(a_a);
	T_INT b(a_b);
	T_INT r;
	if (b > a)
	{
		std::swap(a, b);
	}
	while (b > 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}


int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		memset(isp, true, sizeof(isp));
		int r(1);
		memset(ans, 0, sizeof(ans));
		ans[1] = 1;
		int i;
		for (i = 2; i < n; ++i)
		{
			if ((n % i) == 0)
			{
				if (isp[i])
				{
					int j = i;
					while (j < n)
					{
						isp[j] = false;
						j += i;
					}
				}
			}
			if (isp[i])
			{
				ans[++r] = i;
			}
		}
		for (; i < n; ++i)
		{
			if ((n % i != 0) && (isp[i]))
			{
				ans[++r] = i;
			}
		}
		cout << ((k - 1) / r) * n + ans[(k - 1) % r + 1] << endl;
	}
	return 0;
}
