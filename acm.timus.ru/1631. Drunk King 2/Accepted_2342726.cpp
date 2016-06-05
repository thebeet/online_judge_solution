/*
 * Drunk_King_2.cpp
 *
 *  Created on: 2008-11-13
 *      Author: Administrator
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	cout << std::setprecision(15)<< n * m + (n + m + 1) * (sqrt(2.0) - 1) << endl;
	return 0;
}
