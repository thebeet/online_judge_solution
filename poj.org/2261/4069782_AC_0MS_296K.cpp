/*
 * PKU2261::France_98.cpp
 *
 *  Created on: Sep 14, 2008 2:32:28 PM
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
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N(16);

vector<string> name(N, string());
int poss[16][16];
double win[4][16];

int main()
{
	for (int i = 0; i < N; ++i)
	{
		cin >> name[i];
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> poss[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		win[0][i] = (double)poss[i][i ^ 1] / 100.0;
	}
	for (int k = 0; k < 3; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			int st = (i ^ (1 << (k + 1))) & ~((1 << (k + 1)) - 1);
			int ed = st + (1 << (k + 1));
			double tposs(0.0);
			double swin(0.0);
			for (int j = st; j < ed; ++j)
			{
				tposs += (double)poss[i][j] * win[k][j] / 100.0;
				swin += win[k][j];
			}
			win[k + 1][i] = win[k][i] * tposs / swin;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		cout << setiosflags(ios::left) << setw(10) << name[i] << " p=" << setiosflags(ios::fixed) << setprecision(2) << win[3][i] * 100.0 << "%" << endl;
	}
	return 0;
}
