/*
 * URAL_68_I::Penalty_Time.cpp
 *
 *  Created on: Oct 11, 2008 4:35:55 PM
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
	int t1, t2;
	cin >> t1 >> t2;
	int s(0);
	for (int i = 0; i < 10; ++i)
	{
		int t;
		cin >> t;
		s += t;
	}
	s *= 20;
	if (t1 + s <= t2)
	{
		cout << "No chance." << endl;
	}
	else
	{
		cout << "Dirty debug :(" << endl;
	}
	return 0;
}


