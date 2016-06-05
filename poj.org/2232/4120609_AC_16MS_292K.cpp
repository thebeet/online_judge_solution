/*
 * PKU2232::New_Stone_Forfex_Cloth_Game.cpp
 *
 *  Created on: Sep 24, 2008 2:01:30 PM
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
	int n;
	while (cin >> n)
	{
		int r[256];
		char hands[1024];
		memset(hands, 0, sizeof(hands));
		memset(r, 0, sizeof(r));
		for (int i = 0; i < n; ++i)
		{
			cin >> hands[i];
			++r[(int)(hands[i])];
		}
		int ans(n);
		if ((r['F'] == 0) && (r['C'] > 0)) ans -= r['S'];
		if ((r['S'] == 0) && (r['F'] > 0)) ans -= r['C'];
		if ((r['C'] == 0) && (r['S'] > 0)) ans -= r['F'];
		cout << ans << endl;
	}
	return 0;
}
