/*
 * PKU2282::The_Counting_Problem.cpp
 *
 *  Created on: Aug 26, 2009 2:35:55 PM
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
#include <stdio.h>
#include <algorithm>

using namespace std;
#define INT long long

INT calcn(INT n, int c)
{
	INT ans = 0;
	while (n > 0)
	{
		if ((n % 10) == c)
		{
			++ans;
		}
		n /= 10;
	}
	return ans;
}

INT calc(INT n, int c)
{
	if (c == 0)
	{
		if (n < 0) return -1;
		if (n < 10) return 0;
		return calc((n - 10) / 10, c) * 10 +  calcn(n / 10, c) * (n % 10 + 1) + n / 10;
	}
	if (n < c) return 0;
	if (n < 10) return 1;
	return calc((n - 10) / 10, c) * 10 + n / 10 + calcn(n / 10, c) * (n % 10 + 1) + calc(n % 10, c);
}

int main()
{
	INT n, m;
	setbuf(stdout, NULL);
	while (scanf("%lld%lld", &n, &m), n > 0)
	{
		if (n > m) swap(n, m);
		for (int i = 0; i < 10; ++i)
		{
			printf("%lld ", calc(m, i) - calc(n - 1, i));
		}
		printf("\n");
	}
	return 0;
}
