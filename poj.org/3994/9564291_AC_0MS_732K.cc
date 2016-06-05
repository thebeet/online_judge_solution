/*
 * Probability_One.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int k(0);
	for (int n; (cin >> n) && (n != 0); )
	{
		cout << ++k << ". ";
		int n1 = n * 3;
		cout << ((n1 % 2 == 0) ? "even" : "odd") << " ";
		int n2 = (n1 + ((n1 % 2 == 0) ? 0 : 1)) / 2;
		int n3 = 3 * n2;
		int n4 = n3 / 9;
		cout << n4 << endl;
	}
	return 0;
}
