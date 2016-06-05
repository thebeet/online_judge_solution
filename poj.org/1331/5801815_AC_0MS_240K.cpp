/*
 * Multiply.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int convert(const string &s, const int base)
{
	int ans(0);
	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
	{
		if ((*it - '0') >= base)
		{
			return -1;
		}
		(ans *= base) += ((*it) - '0');
	}
	return ans;
}

int main()
{
	int tn;
	cin >> tn;
	for (int ti = 0; ti < tn; ++ti)
	{
		string a, b, c;
		cin >> a >> b >> c;
		int na, nb, nc;
		bool flag(false);
		for (int base = 2; base <= 16; ++base)
		{
			na = convert(a, base);
			nb = convert(b, base);
			nc = convert(c, base);
			if ((na < 0) || (nb < 0) || (nc < 0))
			{
				continue;
			}
			if ((long long)nc == (long long)na * (long long)nb)
			{
				cout << base << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
