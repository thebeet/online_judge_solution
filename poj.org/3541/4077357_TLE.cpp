/*
 * PKU3541::Given_a_string.cpp
 *
 *  Created on: Sep 15, 2008 7:30:14 PM
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
#include <map>

using namespace std;

vector< pair<int, int> > slot;

map<int, int> hash;

int main()
{
	string inp1, inp2;
	cin >> inp1 >> inp2;
	int len = inp1.size();
	inp1 += inp1;
	vector<int> dinp1(len + len), dinp2(len);
	for (int i = 0; i < len; ++i)
	{
		dinp1[i] = inp1[i] - '0';
		dinp2[i] = inp2[i] - '0';
	}
	for (int i = len; i < len + len; ++i)
	{
		dinp1[i] = inp1[i] - '0';
	}
	vector< int > sums(len);
	vector< int > hashval(len);
	for (int i = 0; i < len; ++i)
	{
		hashval[0] += dinp1[i] * (len - i);
		sums[0] += dinp1[i];
	}
	for (int i = 1; i < len; ++i)
	{
		sums[i] = sums[i - 1] - dinp1[i - 1] + dinp1[len + i - 1];
		hashval[i] = hashval[i - 1] + sums[i] - dinp1[i - 1] * len;
	}

	vector<int> news(len);
	for (int i = 0; i < len; ++i)
	{
		int newhash(0);
		int newsum(0);
		int j;
		for (j = 0; j < len; ++j)
		{
			news[j] = dinp2[j] ^ dinp2[(j + i) % len];
			newhash += news[j] * (len - j);
			newsum += news[j];
		}
		for (j = 0; j < len; ++j)
		{
			if ((sums[j] == newsum) && (newhash == newhash))
			{
				int k;
				for (k = 0; k < len; ++k)
				{
					if (news[k] != dinp1[j + k])
					{
						break;
					}
				}
				if (k == len)
				{
					break;
				}
			}
		}
		if (j < len)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
