/*
 * Prerequisites.cpp
 *
 *  Created on: Sep 25, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main()
{
	int n;
	while (cin >> n, n > 0)
	{
		int m;
		cin >> m;
		map<string, bool> hash;
		for (int i = 0; i < n; ++i)
		{
			string s;
			cin >> s;
			hash[s] = true;
		}
		bool flag(true);
		for (int i = 0; i < m; ++i)
		{
			int s, r;
			cin >> s >> r;
			for (int j = 0; j < s; ++j)
			{
				string s;
				cin >> s;
				if (hash[s])
				{
					--r;
				}
			}
			if (r > 0) flag = false;
		}
		cout << (flag ? "yes" : "no") << endl;
	}
	return 0;
}
