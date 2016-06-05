/*
 * PKU2295::A_DP_Problem.cpp
 *
 *  Created on: Sep 14, 2008 12:32:11 PM
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
#include <cmath>

using namespace std;

char inp[1024];
char inpbak[1024];

pair<int, int> calc(char *inp)
{
	int len = strlen(inp);
	int p[1024];
	p[0] = 1;
	p[1] = 0;
	pair<int, int> ret(0, 0);
	for (int i = 1; i <= len; ++i)
	{
		if ((inp[i] == '-') || (inp[i] == '+') || (inp[i] == '\0'))
		{
			bool flag(true);
			char b = inp[i];
			inp[i] = '\0';
			int d1(0), d2(1);
			if (inp[i - 1] == 'x')
			{
				inp[i - 1] = '1';
				flag = false;
				swap(d1, d2);
			}
			int m(0);
			int dx(0);
			if (p[p[0]] > 0)
			{
				dx = -1;
			}
			sscanf(inp + p[p[0]] + dx, "%d", &m);
			if (flag == false)
			{
				if ((m == 1) || (m == -1))
				{
					m *= 11;
				}
				m /= 10;
			}
			d1 *= m;
			d2 *= m;
			ret.first += d1;
			ret.second += d2;
			inp[i] = b;
			p[++p[0]] = i + 1;
		}
	}
	return ret;
}

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		char *inp1, *inp2;
		int p[1024];
		memset(inp, 0, sizeof(inp));
		cin >> inp;
		int len = strlen(inp);
		memcpy(inpbak, inp, sizeof(inp));
		inp1 = inp;
		for (int i = 0; i < len; ++i)
		{
			if (inp[i] == '=')
			{
				inp2 = inp + i + 1;
				inp[i] = '\0';
				break;
			}
		}
		pair<int, int> r1, r2;
		r1 = calc(inp1);
		r2 = calc(inp2);
		if (r1 == r2)
		{
			cout << "IDENTITY" << endl;
		}
		else if (r1.first == r2.first)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			double retd = (double)(r2.second - r1.second) / (double)(r1.first - r2.first);
			if (retd > 0)
			{
				cout << (int)(retd + 0.0000000001) << endl;
			}
			else
			{
				cout << (int)(retd - 0.9999999999) << endl;
			}
		}
	}

	return 0;
}
