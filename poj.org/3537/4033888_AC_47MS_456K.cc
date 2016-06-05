/*
 * PKU3537::Crosses_and_Crosses.cpp
 *
 *  Created on: Sep 7, 2008 3:46:08 PM
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

int nim[2048];
bool nimuse[2048];

int main()
{
	int i, j, n;
	cin >> n;
	memset(nim, 0, sizeof(nim));
	nim[0] = 0;
	nim[1] = nim[2] = nim[3] = 1;
	nim[4] = 2;
	for (int i = 5; i <= n; ++i)
	{
		memset(nimuse, false, sizeof(nimuse));
		nimuse[nim[i - 3]] = true;
		nimuse[nim[i - 4]] = true;
		nimuse[nim[i - 5]] = true;
		int half = (i - 5) / 2;
		for (int j = 1; j <= half; ++j)
		{
			nimuse[nim[j] ^ nim[i - 5 - j]] = true;
		}
		int minnim(0);
		while (nimuse[minnim])
		{
			++minnim;
		}
		nim[i] = minnim;
	}
	cout << ((nim[n] > 0) ? 1 : 2) << endl;
	return 0;
}
