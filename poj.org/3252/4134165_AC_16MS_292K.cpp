/*
 * PKU3252::Round_Numbers.cpp
 *
 *  Created on: Sep 26, 2008 6:03:17 PM
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

int C[32][32];

void init(void)
{
	memset(C, 0, sizeof(C));
	C[0][0] = 1;
	for (int i = 1; i < 32; ++i)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
}

int calc(const int n)
{
	int bin[64];
	memset(bin, 0, sizeof(n));
	int tn(n);
	int ans(0);
	while (tn > 0)
	{
		bin[++bin[0]] = (tn & 1);
		tn >>= 1;
		if (tn > 0)
		{
			int t(bin[0] - 1);
			for (int j = t; j >= (t + 1 - j); --j)
			{
				ans += C[t][j];
			}
		}
	}
	int s(0);
	for (int i = bin[0] - 1; i >= 1; --i)
	{
		if (bin[i] == 1)
		{
			int t(i - 1);
			for (int j = t; (j >= (t + s - j)) && (j >= 0); --j)
			{
				ans += C[t][j];
			}
			++s;
		}
		else
		{
			--s;
		}
	}
	return ans;
}

int main()
{
	int st, ed;
	init();
	cin >> st >> ed;
	cout << calc(ed + 1) - calc(st) << endl;
	return 0;
}
