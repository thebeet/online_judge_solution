/*
 * Optimal_Parking.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */
#include <iostream>

using namespace std;

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		int n;
		cin >> n;
		int mn(1000), mx(-1000);
		for (int i = 1; i <= n; ++i)
		{
			int m;
			cin >> m;
			mn = min(mn, m);
			mx = max(mx, m);

		}
		cout << (mx - mn) * 2 << endl;
	}
	return 0;
}
