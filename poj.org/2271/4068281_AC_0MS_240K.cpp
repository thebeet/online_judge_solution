/*
 * HTML.cpp
 *
 *  Created on: 2008-9-14
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int pos(-1);
	string inp;
	while (cin >> inp)
	{
		if (inp == "<hr>")
		{
			if (pos != -1)
			{
				cout << endl << string(80, '-') << endl;
				pos = -1;
			}
			else
			{
				cout << string(80, '-') << endl;
			}
		}
		else if (inp == "<br>")
		{
			pos = -1;
			cout << endl;
		}
		else
		{
			while (true)
			{
				if (pos + 1 + inp.size() <= 80)
				{
					if (pos >= 0)
					{
						cout << " ";
					}
					pos += 1 + inp.size();
					cout << inp;
					break;
				}
				else
				{
					cout << endl;
					pos = -1;
				}
			}
		}
	}
	return 0;
}
