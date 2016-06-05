/*
 * URAL1658::Sum_of_Digits.cpp
 *
 *  Created on: Nov 5, 2008 10:31:56 AM
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

using namespace std;

typedef int *INT_P;
typedef char *CHAR_P;

INT_P len[5010];
CHAR_P ans[5010];

void init(void)
{
	for (int i = 0; i <= 5005; ++i)
	{
		len[i] = new int [5010 - i];
		ans[i] = new char [5010 - i];
		memset(len[i], 34, sizeof(int) * (5010 - i));
		memset(ans[i], 0, sizeof(char) * (5010 - i));
	}
}


int &getlen(const int s1, const int s2)
{
	return len[s1][(s2 - s1 - s1) / 2];
}
char &getans(const int s1, const int s2)
{
	return ans[s1][(s2 - s1 - s1) / 2];
}

char calc(const int s1, const int s2)
{
	if ((s2 - s1 - s1) < 0)
	{
		return '*';
	}
	if (getans(s1, s2) == '\0')
	{
		if (s1 == 0)
		{
			getans(s1, s2) = '*';
			return '*';
		}
		int p = 1;
		calc(s1 - 1, s2 - 1);
		int m = getlen(s1 - 1, s2 - 1);
		for (int i = 2; i < 10; ++i)
		{
			if (((s1 - i) < 0) || ((s2 - i * i) < 0))
			{
				break;
			}
			calc(s1 - i, s2 - i * i);
			int tm = getlen(s1 - i, s2 - i * i);
			if (tm < m)
			{
				m = tm;
				p = i;
			}
		}
		if (m > 100000)
		{
			getans(s1, s2) = '*';
		}
		else
		{
			getans(s1, s2) = p;
			getlen(s1, s2) = m + 1;
		}
	}
	return getans(s1, s2);
}

int main()
{
	int n;
	scanf("%d", &n);
	init();
	ans[0][0] = '@';
	len[0][0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		if ((s2 < s1) || (((s2 - s1) % 2) == 1))
		{
			printf("No solution\n");
			continue;
		}
		while (s1 + s1 > s2)
		{
			printf("1");
			--s1;
			--s2;
		}
		if (calc(s1, s2) == '*')
		{
			printf("No solution\n");
			break;
		}
		while (s1 > 0)
		{
			int d = calc(s1, s2);
			printf("%c", d + '0');
			s1 -= d;
			s2 -= d * d;
		}
		printf("\n");
	}
	return 0;
}
