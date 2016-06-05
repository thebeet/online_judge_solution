/*
 * URAL1644::A_Whole_Lot_of_Walnuts.cpp
 *
 *  Created on: Oct 26, 2008 9:37:45 PM
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
#include <string>
using namespace std;

bool hun[16];

int main()
{
	int n;
	cin >> n;
	int mins(10);
	memset(hun, false, sizeof(hun));
	hun[0] = true;
	for (int i = 0; i < n; ++i)
	{
		int m;
		string inp;
		cin >> m >> inp;
		if (inp[0] == 'h')
		{
			hun[m] = true;
		}
		else
		{
			mins = min(mins, m);
		}
	}
	int p = mins - 1;
	while (hun[p] == false)
	{
		--p;
	}
	if (p > 0)
	{
		cout << mins << endl;
	}
	else
	{
		cout << "Inconsistent" << endl;
	}
	return 0;
}


