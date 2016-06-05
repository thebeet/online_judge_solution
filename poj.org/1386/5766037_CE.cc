/*
 * PKU1386::Play_on_Words.cpp
 *
 *  Created on: Aug 27, 2009 6:43:35 PM
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
#include <cstring>
#include <cstdio>

using namespace std;

char inpbuf[1024];

bool basemap[128][128];
bool gone[128];

void go(const int p)
{
	if (gone[p] == false)
	{
		gone[p] = true;
		for (int i = 'a'; i <= 'z'; ++i)
		{
			if (basemap[p][i])
			{
				go(i);
			}
		}
	}
}

bool check()
{
	go('a');
	for (int i = 'a'; i <= 'z'; ++i)
	{
		if (gone[i] == false)
		{
			return false;
		}
	}
	return true;
}

int inp[128];
int out[128];

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		scanf("%d", &n);
		memset(basemap, 0, sizeof(basemap));
		memset(inp, 0, sizeof(inp));
		memset(out, 0, sizeof(out));
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", inpbuf);
			char s = inpbuf[0];
			char t = inpbuf[strnlen(inpbuf, 1024) - 1];
			++inp[s];
			++out[t];
			basemap[s][t] = true;
			basemap[t][s] = true;
		}
		int ina(0), inb(0);
		for (int i = 'a'; i <= 'z'; ++i)
		{
			if (inp[i] != out[i])
			{
				if (inp[i] + 1 == out[i])
				{
					++ina;
				}
				else if (inp[i] - 1 == out[i])
				{
					++inb;
				}
				else
				{
					ina = 2;
					break;
				}
			}
		}
		cout << (((ina <= 1) && (inb <= 1)) ? "Ordering is possible." : "The door cannot be opened.") << endl;
	}
	return 0;
}
