/*
 * URAL_70_F::Cipher_Message.cpp
 *
 *  Created on: Nov 1, 2008 8:03:06 PM
 *      Author: TheBeet
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Affero General Public License as
 *	published by the Free Software Foundation, either version 3 of the
 *	License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Affero General Public License for more details.
 *
 *	You should have received a copy of the GNU Affero General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string inp;
	string oup;
	cin >> inp;
	for (int i = 0; i < inp.size(); ++i)
	{
		if ((oup.size() > 0) && (oup[oup.size() - 1] == inp[i]))
		{
			oup.erase(oup.size() - 1);
		}
		else
		{
			oup.push_back(inp[i]);
		}
	}
	cout << oup << endl;
	return 0;
}


