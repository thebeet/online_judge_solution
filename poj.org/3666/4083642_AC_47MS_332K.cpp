/*
 * PKU3666::Making_the_Grade.cpp
 *
 *  Created on: Sep 17, 2008 12:56:17 PM
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
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> grade(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> grade[i];
	}
	vector<int> gradesort(grade);
	sort(gradesort.begin() + 1, gradesort.end());
	vector< vector<int> > dp(2, vector<int>(n + 1, 0));
	int p0(0), p1(1);
	for (int i = 0; i < n; ++i)
	{
		dp[p0][0] = dp[p1][0] + abs(grade[i] - gradesort[0]);
		for (int j = 1; j < n; ++j)
		{
			dp[p0][j] = min(dp[p0][j - 1], dp[p1][j] + abs(grade[i] - gradesort[j]));
		}
		swap(p0, p1);
	}
	cout << dp[p1][n - 1] << endl;
	return 0;
}
