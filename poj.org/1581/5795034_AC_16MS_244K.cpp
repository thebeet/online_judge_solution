/*
 * A_Contesting_Decision.cpp
 *
 *  Created on: Sep 1, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int ans;
	int ansolve(-1);
	string ansname;
	for (int i = 0; i < n; ++i)
	{
		string name;
		cin >> name;
		int pen(0);
		int solve(0);
		for (int j = 0; j < 4; ++j)
		{
			int s, t;
			cin >> s >> t;
			if (t > 0)
			{
				t += (s - 1) * 20;
				++solve;
			}
			pen += t;
		}
		if ((solve > ansolve) || ((solve == ansolve) && (pen < ans)))
		{
			ansolve = solve;
			ans = pen;
			ansname = name;
		}
	}
	cout << ansname << " " << ansolve << " " << ans << endl;
	return 0;
}
