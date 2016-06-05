/*
 * PKU3192::DNA_Assembly.cpp
 *
 *  Created on: Oct 7, 2008 3:23:49 PM
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

void cat(string &str1, const string &str2)
{
	int len = min(str1.size(), str2.size());
	int i;
	for (i = len; i >= 1; --i)
	{
		if (str1.substr(str1.size() - i, i) ==
			str2.substr(0, i))
		{
			break;
		}
	}
	str1.resize(str1.size() - i);
	str1 += str2;
}

int main()
{
	int n;
	cin >> n;
	vector<string> strs(n);
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> strs[i];
		perm[i] = i;
	}
	unsigned int ansp(0x7fffffff);
	do
	{
		string merge_str(strs[perm[0]]);
		for (int i = 1; i < n; ++i)
		{
			cat(merge_str, strs[perm[i]]);
		}
//		cerr << merge_str << endl;
		if (ansp > merge_str.size())
		{
			ansp = merge_str.size();
		}
	}while(next_permutation(perm.begin(), perm.end()));
	cout << ansp << endl;
	return 0;
}

