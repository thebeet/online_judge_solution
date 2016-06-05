/*
 * 1D_Maze.cpp
 *
 *  Created on: 2008-11-13
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	int ix(100000);
	int dx(-100000);
	for (int i = 0; i < n; ++i)
	{
		int ob;
		cin >> ob;
		if (ob > 0) ix = min(ix, ob);
		if (ob < 0) dx = max(dx, ob);
	}
	if ((ix > x) && (dx < x))
	{
		if (x > 0)
		{
			cout << x << " " << x - dx * 2 << endl;
		}
		else
		{
			cout << ix * 2 - x << " " << -x << endl;
		}
	}
	else
	{
		cout << "Impossible" << endl;
	}
	return 0;
}
