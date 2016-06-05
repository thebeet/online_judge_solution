/*
 * PKU3614::Sunscreen.cpp
 *
 *  Created on: Sep 24, 2008 8:35:58 PM
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

struct Cow
{
	int minspf, maxspf;
};

bool operator < (const Cow &c1, const Cow &c2)
{
	return c1.minspf < c2.minspf;
}

Cow cows[4096];
int lotion[1024];

int main()
{
	int c, l;
	cin >> c >> l;
	for (int i = 0; i < c; ++i)
	{
		cin >> cows[i].minspf >> cows[i].maxspf;
	}
	memset(lotion, 0, sizeof(lotion));
	for (int i = 0; i < l; ++i)
	{
		int spf, cov;
		cin >> spf >> cov;
		lotion[spf] += cov;
	}
	lotion[1001] = 100000;
	sort(cows, cows + c);
	int ans(0);
	int p(0);
	while (lotion[p] == 0) ++p;
	for (int i = 0; i < c; ++i)
	{
		if (cows[i].minspf > p)
		{
			p = cows[i].minspf;
			while (lotion[p] == 0) ++p;
		}
		if (cows[i].maxspf >= p)
		{
			++ans;
			--lotion[p];
			while (lotion[p] == 0) ++p;
		}
	}
	cout << ans << endl;
	return 0;
}
