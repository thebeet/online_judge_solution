/*
 * PKU2549::Sumsets.cpp
 *
 *  Created on: Sep 28, 2008 4:29:55 PM
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
#include <map>

using namespace std;

int inp[1024];

multimap<int, pair<int, int> > Sums;

int main()
{
	int n;
	while (scanf("%d", &n), n > 0)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &inp[i]);
		}
		sort(inp, inp + n);
		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				int sum = inp[i] + inp[j];
				Sums.insert(make_pair(sum, make_pair(i, j)));
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j)
				{
					break;
				}
				int s(inp[i] - inp[j]);
				for (multimap<int, pair<int, int> >::iterator it = Sums.lower_bound(s);
					 it != Sums.end(); ++it)
				{
					if (it->first != s) break;
					if ((it->second.first != i) && (it->second.first != j) &&
						(it->second.second != i) && (it->second.second != j))
					{
						cout << inp[i] << endl;
						goto next;
					}
				}
			}
		}
		cout << "no solution" << endl;
next:
		;
	}
	return 0;
}
