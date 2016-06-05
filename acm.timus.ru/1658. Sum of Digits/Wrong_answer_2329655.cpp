/*
 * URAL1658::Sum_of_Digits.cpp
 *
 *  Created on: Nov 5, 2008 10:31:56 AM
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

using namespace std;

const int MAXN = 10120;

int dp[MAXN];
int pre[MAXN];
int ans[16];

int main()
{
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 9; i >= 2; --i)
	{
		int k = i * i - i;
		for (int j = 0; j <= 10000; ++j)
		{
			if ((dp[j] >= 0) && (dp[j + k] < 0))
			{
				dp[j + k] = dp[j] + i;
				pre[j + k] = j;
			}
		}
	}
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		int d = s2 - s1;
		if ((d < 0) || (dp[d] == -1) || (dp[d] > s1))
		{
			cout << "No solution" << endl;
			continue;
		}
		memset(ans, 0, sizeof(ans));
		int pp(d);
		while (pp > 0)
		{
			++ans[dp[pp] - dp[pre[pp]]];
			pp = pre[pp];
		}
		for (int i = 0; i < s1 - dp[d]; ++i)
		{
			printf("1");
		}
		for (int i = 2; i <= 9; ++i)
		{
			for (int j = 0; j < ans[i]; ++j)
			{
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}


