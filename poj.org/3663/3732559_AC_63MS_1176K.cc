/*
 * Costume_Party.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */
#include <iostream>
#include <algorithm>

using namespace std;

int leng[65536];

int main()
{
	int i, n, s;
	cin >> n >> s;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &leng[i]);
	}
	sort(leng, leng + n);
	int p = n - 1;
	int ans(0);
	for (i = 0; i < p; ++i)
	{
		while ((i < p) && (leng[i] + leng[p] > s))
		{
			--p;
		}
		ans += (p - i);
	}
	cout << ans << endl;
	return 0;
}
