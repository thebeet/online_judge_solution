/*
 * Bomb_Game.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

struct Mat
{
	int r, s, p, t;
};

int main()
{
	int a, b, k;
	cin >> a >> b >> k;
	vector<Mat> mats(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> mats[i].r >> mats[i].s >> mats[i].p >> mats[i].t;
		mats[i].p /= 2;
	}
	int sum(0);
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			bool flag(true);
			for (int h = 0; h < k; ++h)
			{
				bool isin = ((abs(mats[h].r - i) <= mats[h].p) && (abs(mats[h].s - j) <= mats[h].p));
				if (isin ^ (mats[h].t == 1))
				{
					flag = false;
					break;
				}
			}
			if (flag) ++sum;
		}
	}
	cout << sum << endl;
	return 0;
}
