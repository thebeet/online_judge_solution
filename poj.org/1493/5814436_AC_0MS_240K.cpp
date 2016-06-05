/*
 * Machined_Surfaces.cpp
 *
 *  Created on: 2009-9-5
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		string inp;
		int sum(0);
		int m(0);
		for (int i = 0; i < n; ++i)
		{
			cin >> inp;
			int len1 = inp.size();
			int len2(0);
			if (inp.size() < 25)
			{
				cin >> inp;
				len2 = inp.size();
			}
			len1 += len2;
			sum += 25 - len1;
			m = max(m, len1);
		}
		cout << sum - (25 - m) * n << endl;
	}
	return 0;
}
