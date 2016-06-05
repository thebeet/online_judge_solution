/*
 * PKU2218::Does_This_Make_Me_Look_Fat.cpp
 *
 *  Created on: Sep 14, 2008 12:51:43 PM
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
#include <vector>

using namespace std;

struct Fat
{
	int w;
	string name;
};

bool operator < (const Fat &f1, const Fat &f2)
{
	return f1.w > f2.w;
}

int main()
{
	vector<Fat> fats;
	string name;
	while (cin >> name)
	{
		fats.clear();
		while ((cin >> name), name != "END")
		{
			int d, w;
			cin >> d >> w;
			w -= d;
			Fat newfat;
			newfat.w = w;
			newfat.name = name;
			fats.push_back(newfat);
		}
		sort(fats.begin(), fats.end());
		for (vector<Fat>::iterator it = fats.begin(); it != fats.end(); ++it)
		{
			cout << it->name << endl;
		}
		cout << endl;
	}
	return 0;
}
