/*
 * PKU1607::Deck.cpp
 *
 *  Created on: Aug 27, 2009 9:44:14 PM
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

double ans[1000000];

int main()
{
	ans[1] = 0.5;
	for (int i = 2; i <= 999999; ++i)
	{
		ans[i] = ans[i - 1] + 1.0 / i / 2.0;
	}
	int n;
	cout << "Cards  Overhang" << endl;
	while (cin >> n)
	{
		printf("%5d  %8.3lf\n", n, ans[n]);
	}
	return 0;
}
