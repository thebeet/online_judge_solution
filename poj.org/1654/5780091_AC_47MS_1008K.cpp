/*
 * Area.cpp
 *
 *  Created on: 2009-8-29
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>

using namespace std;

char inp[1000010];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", inp);
		long long s(0);
		int xp(0), yp(0);
		for (char *c = inp; *c != '5'; ++c)
		{
			int nextx(xp);
			int nexty(yp);
			if ((*c == '1') || (*c == '4') || (*c == '7'))
			{
				--nextx;
			}
			if ((*c == '3') || (*c == '6') || (*c == '9'))
			{
				++nextx;
			}
			if ((*c == '1') || (*c == '2') || (*c == '3'))
			{
				--nexty;
			}
			if ((*c == '7') || (*c == '8') || (*c == '9'))
			{
				++nexty;
			}
			s += xp * nexty - yp * nextx;
			xp = nextx;
			yp = nexty;
		}
		s += xp * 0 - yp * 0;
		if (s < 0) s = -s;
		cout << (s / 2LL);
		if (s & 1LL)
		{
			cout << ".5";
		}
		cout << endl;
	}
	return 0;
}
