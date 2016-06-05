/*
 * PKU3654::Electronic_Document_Security.cpp
 *
 *  Created on: Oct 9, 2008 7:09:04 PM
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

int main()
{
	string inp;
	int ti(0);
	while ((cin >> inp), inp != "#")
	{
		cout << ++ti << ":";
		map<char, map<char, bool> > ans;
		map<char, string> ansstr;
		string token;
		ans.clear();
		ansstr.clear();
		int pos;
		while (inp.size() > 0)
		{
			string op;
			if ((pos = inp.find(',')) == inp.npos)
			{
				token = inp;
				inp = "";
			}
			else
			{
				token = inp.substr(0, pos);
				inp = inp.substr(pos + 1, inp.size() - pos - 1);
			}
			string left, right;
			if ((pos = token.find('-')) != token.npos)
			{
				left = token.substr(0, pos);
				right = token.substr(pos + 1, token.size() - pos - 1);
				op = "-";
				for (int i = 0; i < left.size(); ++i)
				{
					for (int j = 0; j < right.size(); ++j)
					{
						ans[left[i]].erase(right[j]);
					}
				}
			}
			else if ((pos = token.find('+')) != token.npos)
			{
				left = token.substr(0, pos);
				right = token.substr(pos + 1, token.size() - pos - 1);
				op = "+";
				for (int i = 0; i < left.size(); ++i)
				{
					for (int j = 0; j < right.size(); ++j)
					{
						ans[left[i]][right[j]] = true;
					}
				}
			}
			else if ((pos = token.find('=')) != token.npos)
			{
				left = token.substr(0, pos);
				right = token.substr(pos + 1, token.size() - pos - 1);
				op = "=";
				map<char, bool> newans;
				for (int j = 0; j < right.size(); ++j)
				{
					newans[right[j]] = true;
				}
				for (int i = 0; i < left.size(); ++i)
				{
					ans[left[i]] = newans;
				}
			}
//			cerr << left << " " << op << "  " << right << endl;
		}
		char pre = '\0';
		for (char a = 'A'; a <= 'Z'; ++a)
		{
			if (ans[a].size() == 0)
			{
				continue;
			}
			else
			{
				if (pre != '\0')
				{
					for (char b = 'a'; b <= 'z'; ++b)
					{
						if (ans[a][b])
						{
							ansstr[a].push_back(b);
						}
					}
					if (ansstr[a] == ansstr[pre])
					{
						cout << a;
					}
					else
					{
						cout << ansstr[pre] << a;
					}
					pre = a;
				}
				else
				{
					pre = a;
					for (char b = 'a'; b <= 'z'; ++b)
					{
						if (ans[a][b])
						{
							ansstr[a].push_back(b);
						}
					}
					cout << a;
				}
			}
		}
		if (pre != '\0')
		{
			cout << ansstr[pre];
		}
		cout << endl;
	}
	return 0;
}

