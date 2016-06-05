/*
 * Party.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	while (b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int g(1);
		bool flag(true);
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin >> a;
			if (a == 0) continue;
			if (flag)
			{
				int gc = gcd(g, a);
				int pa = a / gc;
				if (1000000 / g <= pa)
				{
					flag = false;
					continue;
				}
				g *= pa;
			}
		}
		if (flag)
		{
			cout << "The CEO must bring " << g << " pounds." << endl;
		}
		else
		{
			cout << "Too much money to pay!" << endl;
		}
	}
}
