/*
 * PKU1606::Jugs.cpp
 *
 *  Created on: Aug 28, 2009 2:02:09 PM
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
#include <queue>
#include <vector>

using namespace std;

int gone[1024][1024];
pair<int, int> pre[1024][1024];
vector<int> ans;

bool flag;
pair<int, int> s;
int ca, cb, n;

void insert(queue< pair<int, int> > &q, const pair<int, int> &p, const int c, const pair<int, int> &ppre)
{
	if (gone[p.first][p.second] == 0)
	{
		gone[p.first][p.second] = c;
		pre[p.first][p.second] = ppre;
		q.push(p);
		if (p.second == n)
		{
			flag = true;
			s = p;
		}
	}
}

int main()
{
	while (cin >> ca >> cb >> n)
	{
		memset(gone, 0, sizeof(gone));
		flag = false;
		queue< pair<int, int> > q;
		while (q.empty() == false)
		{
			q.pop();
		}
		q.push(make_pair(0, 0));
		for ( ; ; )
		{
			pair<int, int> fr = q.front();
			q.pop();
			insert(q, make_pair(ca, fr.second), 1, fr);
			insert(q, make_pair(fr.first, cb), 2, fr);
			insert(q, make_pair(0, fr.second), 3, fr);
			insert(q, make_pair(fr.first, 0), 4, fr);
			if (fr.first > cb - fr.second)
			{
				insert(q, make_pair(fr.first - (cb - fr.second), cb), 5, fr);
			}
			else
			{
				insert(q, make_pair(0, fr.first + fr.second), 5, fr);
			}
			if (fr.second > ca - fr.first)
			{
				insert(q, make_pair(ca, fr.second - (ca - fr.first)), 6, fr);
			}
			else
			{
				insert(q, make_pair(fr.first + fr.second, 0), 6, fr);
			}
			if (flag)
			{
				ans.clear();
				while ((s.first > 0) || (s.second > 0))
				{
					ans.push_back(gone[s.first][s.second]);
					s = pre[s.first][s.second];
				}
				for (vector<int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); ++it)
				{
					switch (*it)
					{
						case 1:
						{
							cout << "fill A" << endl;
							break;
						}
						case 2:
						{
							cout << "fill B" << endl;
							break;
						}
						case 3:
						{
							cout << "empty A" << endl;
							break;
						}
						case 4:
						{
							cout << "empty B" << endl;
							break;
						}
						case 5:
						{
							cout << "pour A B" << endl;
							break;
						}
						case 6:
						{
							cout << "pour B A" << endl;
							break;
						}
					}
				}
				cout << "success" << endl;
				break;
			}
		}
	}
	return 0;
}
