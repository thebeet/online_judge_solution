/*
 * Yogurt_factory.cpp
 *
 *  Created on: Sep 1, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, s;
	int ans(0);
	cin >> n >> s;
	int pc(10000);
	for (int i = 0; i < n; ++i)
	{
		int c, y;
		cin >> c >> y;
		pc = min(pc + s, c);
		ans += pc * y;
	}
	cout << ans << endl;
	return 0;
}
