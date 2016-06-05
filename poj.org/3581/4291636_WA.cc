/*
 * PKU3581::Sequence.cpp
 *
 *  Created on: Oct 29, 2008 6:38:49 PM
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

int arr[200010];

int MinimumRepresentation(const int *arr, const int n)
{
	int i(0), j(1), k(0);
	while ((i < n) && (j < n) && (k < n))
	{
		int t = arr[(i + k) % n] - arr[(j + k) % n];
		if (t == 0)
		{
			++k;
		}
		else
		{
			((t > 0) ? i : j) += k + 1;
			if (i == j) ++j;
			k = 0;
		}
	}
	return min(i, j);
}

int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		int p1 = MinimumRepresentation(arr, n - 2);
		int p2 = MinimumRepresentation(arr + p1, n - p1 - 2);
		p2 += p1 + 1;
		for (int i = p1; i >= 0; --i)
		{
			printf("%d\n", arr[i]);
		}
		for (int i = p2; i > p1; --i)
		{
			printf("%d\n", arr[i]);
		}
		for (int i = n - 1; i > p2; --i)
		{
			printf("%d\n", arr[i]);
		}
	}
	return 0;
}


