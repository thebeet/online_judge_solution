/*
 * Buttons.cpp
 *
 *  Created on: Sep 1, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 3; i * i <= n; ++i)
	{
		if ((n % i) == 0)
		{
			cout << (i - 1) << endl;
			return 0;
		}
	}
	if (((n % 2) == 0) && (n > 4))
	{
		cout << ((n / 2) - 1) << endl;
	}
	else
	{
		cout << n - 1 << endl;
	}
	return 0;
}
