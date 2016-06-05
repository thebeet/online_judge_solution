/*
 * PKU3702::Chessman.cpp
 *
 *  Created on: Oct 5, 2008 12:24:30 PM
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
#include <queue>
#include <map>

using namespace std;

string inp1, inp2;

const int MAXN = 64;

bool dp[MAXN][MAXN][MAXN][MAXN];

int ans[4];
int ans1[4], ans2[4];

int k(0);

void fill(const int ans[4])
{
	if (dp[ans[0]][ans[1]][ans[2]][ans[3]])
	{
		return;
	}
//	cout << "***" << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
	dp[ans[0]][ans[1]][ans[2]][ans[3]] = true;
	if (dp[ans2[0]][ans2[1]][ans2[2]][ans2[3]])
	{
		return;
	}
	int ans_b[4];
	for (int i = 0; i < 4; ++i)
	{
		if (ans[i] > 0)
		{
			if ((ans[(i + 1) & 3] <= 9) && (ans[(i + 2) & 3] > 0) && (ans[(i + 3) & 3] <= 9))
			{
				memcpy(ans_b, ans, sizeof(int) * 4);
				--ans_b[i];
				++ans_b[(i + 1) & 3];
				--ans_b[(i + 2) & 3];
				++ans_b[(i + 3) & 3];
				fill(ans_b);
			}
			if ((ans[(i + 1) & 3] > 0) && (ans[(i + 2) & 3] <= 9))
			{
				memcpy(ans_b, ans, sizeof(int) * 4);
				--ans_b[i];
				--ans_b[(i + 1) & 3];
				++ans_b[(i + 2) & 3];
				fill(ans_b);
			}
		}
	}
}

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		cin >> inp1 >> inp2;
		memset(ans1, 0, sizeof(ans1));
		memset(ans2, 0, sizeof(ans2));
		memset(dp, false, sizeof(dp));
		for (unsigned int i = 0; i < inp1.size(); ++i)
		{
			if (inp1[i] == '*') ++ans1[i & 3];
			if (inp2[i] == '*') ++ans2[i & 3];
		}
		//cout << ans1[0] << ans1[1] << ans1[2] << ans1[3] << endl;
		//cout << ans2[0] << ans2[1] << ans2[2] << ans2[3] << endl;
		fill(ans1);
		if (dp[ans2[0]][ans2[1]][ans2[2]][ans2[3]])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
