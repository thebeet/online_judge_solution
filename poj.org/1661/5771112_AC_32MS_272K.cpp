/*
 * PKU1661::Help_Jimmy.cpp
 *
 *  Created on: Aug 28, 2009 2:30:46 PM
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

struct Platform
{
	Platform() :
		t(1000000000), tx(1000000000), ty(1000000000)
	{
	}
	int h, x, y;
	int t;
	int tx, ty;
};

istream &operator >> (istream &in, Platform &p)
{
	return in>> p.x >> p.y >> p.h ;
}

bool operator < (const Platform &p1, const Platform &p2)
{
	return p1.h > p2.h;
}

Platform ps[1024];

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, x, h, m;
		cin >> n >> x >> h >> m;
		for (int i = 0; i < n; ++i)
		{
			ps[i] = Platform();
			cin >> ps[i];
		}
		sort(ps, ps + n);
		ps[n].h = 0;
		ps[n].x = -10000000;
		ps[n].y = 10000000;
		int i;
		for (i = 0; i <= n; ++i)
		{
			if ((x >= ps[i].x) && (x <= ps[i].y))
			{
				ps[i].t = h - ps[i].h;
				ps[i].tx = (h - ps[i].h) + x - ps[i].x;
				ps[i].ty = (h - ps[i].h) + ps[i].y - x;
				break;
			}
		}
		for ( ; i <= n; ++i)
		{
			if (ps[i].t < 1000000000)
			{
				bool flagx(true);
				bool flagy(true);
				for (int j = i + 1; j <= n; ++j)
				{
					if ((ps[i].h - ps[j].h) > m) break;
					if (((ps[i].x >= ps[j].x) && (ps[i].x <= ps[j].y)) && flagx)
					{
						ps[j].t = min(ps[j].t, ps[i].h - ps[j].h + ps[i].tx);
						ps[j].tx = min(ps[j].tx, (ps[i].h - ps[j].h + ps[i].tx) + ps[i].x - ps[j].x);
						ps[j].ty = min(ps[j].ty, (ps[i].h - ps[j].h + ps[i].tx) + ps[j].y - ps[i].x);
						flagx = false;
						if (flagy == false) break;
					}
					if (((ps[i].y >= ps[j].x) && (ps[i].y <= ps[j].y)) && flagy)
					{
						ps[j].t = min(ps[j].t, ps[i].h - ps[j].h + ps[i].ty);
						ps[j].tx = min(ps[j].tx, (ps[i].h - ps[j].h + ps[i].ty) + ps[i].y - ps[j].x);
						ps[j].ty = min(ps[j].ty, (ps[i].h - ps[j].h + ps[i].ty) + ps[j].y - ps[i].y);
						flagy = false;
						if (flagx == false) break;
					}
				}
			}
		}
		cout << ps[n].t << endl;
	}
	return 0;
}
