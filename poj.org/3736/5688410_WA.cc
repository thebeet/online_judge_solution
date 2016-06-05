/*
 * PKU3736::Snipe_the_Sniper.cpp
 *
 *  Created on: Aug 18, 2009 2:09:13 PM
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
#include <cmath>

using namespace std;

struct Enemy
{
	double dis;
	int dam;
	double stuntime;

}es[128];

bool operator < (const Enemy &e1, const Enemy &e2)
{
	return e1.dis < e2.dis;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			double x, y, r;
			cin >> x >> y >> es[i].stuntime >> r >> es[i].dam;
			es[i].dis = max(sqrt((x - 100) * (x - 100) + y * y) - r, 0.0);
		}
		sort(es + 0, es + n);
		int t(100);
		int hp;
		cin >> hp;
		for (int i = 0; i < n; ++i)
		{
			if (es[i].dis - 0.0000001 < t)
			{
				hp -= es[i].dam;
				t += es[i].stuntime;
				if (hp <= 0)
				{
					break;
				}
			}
		}
		cout << ((hp <= 0) ? "Danger!" : "Safe!") << endl;
	}
	return 0;
}
