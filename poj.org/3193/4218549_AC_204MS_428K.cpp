/*
 * PKU3193::Cow_Phrasebook.cpp
 *
 *  Created on: Oct 7, 2008 2:03:43 PM
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
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	string inp;
	getline(cin, inp);
	vector<string> phrases(n);
	for (int i = 0; i < n; ++i)
	{
		getline(cin, phrases[i]);
	}
	sort(phrases.begin(), phrases.end());
	int ans(0);
	for (int i = 0; i < m; ++i)
	{
		getline(cin, inp);
		if (phrases[0] >= inp)
		{
			if (phrases[0].substr(0, inp.size()) == inp)
			{
				++ans;
			}
			continue;
		}

		int lo(0), hi(n);
		while (lo + 1 < hi)
		{
			int mid((lo + hi) >> 1);
			((phrases[mid] >= inp) ? hi : lo) = mid;
		}
		if (phrases[lo] == inp)
		{
			++ans;
			continue;
		}
		if (hi != n)
		{
			if (phrases[hi].substr(0, inp.size()) == inp)
			{
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

