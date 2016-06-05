/*
 * PKU3544::Journey_with_Pigs.cpp
 *
 *  Created on: Sep 7, 2008 2:14:55 PM
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

struct Price
{
	long long p;
	int id;
};

Price pig[1024];

bool operator < (const Price &p1, const Price &p2)
{
	return p1.p < p2.p;
}

Price price[1024];
long long dis[1024];
int ans[1024];

int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 0; i < n; ++i)
	{
		cin >> pig[i].p;
		pig[i].id = i + 1;
	}
	sort(pig, pig + n);
	for (int i = 0; i < n; ++i)
	{
		cin >> dis[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i].p;
		price[i].p -= t * dis[i];
		price[i].id = i + 1;
	}
	sort(price, price + n);
	for (int i = 0; i < n; ++i)
	{
		ans[price[i].id] = pig[i].id;
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}
