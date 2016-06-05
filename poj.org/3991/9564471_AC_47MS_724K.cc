/*
 * Seinfeld.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string inp;
	int ti(0);
	while ((cin >> inp), (inp[0] != '-'))
	{
		int st(0);
		int ans(0);
		for (int i = 0; i < inp.size(); ++i)
		{
			if (inp[i] == '{')
			{
				++st;
			}
			else
			{
				if (st == 0)
				{
					++ans;
					++st;
				}
				else
				{
					--st;
				}
			}
		}
		cout << ++ti << ". " << ans + st / 2 << endl;
	}
}
