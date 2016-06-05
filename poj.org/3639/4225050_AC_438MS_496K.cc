/*
 * PKU3639::Exchange_Rates.cpp
 *
 *  Created on: Oct 15, 2008 4:29:23 PM
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
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int can(100000);
		int us(0);
		for (int i = 0; i < n; ++i)
		{
			double rate;
			cin >> rate;
			int nowcan = max(can, (int)(us * rate * .97));
			int nowus = max(us, (int)(can / rate * .97));
			can = nowcan;
			us = nowus;
		}
		cout << can / 100 << '.' << setfill('0') << setw(2) << can % 100 << endl;
	}


	return 0;
}


