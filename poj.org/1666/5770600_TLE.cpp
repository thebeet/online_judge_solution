/*
 * PKU1666::Candy_Sharing_Game.cpp
 *
 *  Created on: Aug 28, 2009 1:14:33 PM
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

int n;
int arr[2][1024];
int p0(0), p1(1);

int doit()
{
	int tim(0);
	for ( ; ; )
	{
		int i;
		for (i = 1; i < n; ++i)
		{
			if (arr[p0][i] != arr[p0][0]) break;
		}
		if (i == n)
		{
			return tim;
		}
		for (int i = 1; i < n; ++i)
		{
			arr[p1][i] = (arr[p0][i] + arr[p0][i - 1]) / 2;
			if (arr[p1][i] & 1)
			{
				++arr[p1][i];
			}
		}
		arr[p1][0] = (arr[p0][n - 1] + arr[p0][0] + 1) / 2;
		swap(p1, p0);
		++tim;
	}
}

int main()
{
	while ((cin >> n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[0][i];
		}
		p0 = 0;
		p1 = 1;
		cout << doit() - 1 << " ";
		cout << arr[p0][0] << endl;
	}
	return 0;
}
