#/*
 * Oulipo.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */
#include <iostream>
#include <algorithm>

using namespace std;

char w[65536];
char t[1001000];
int lw, lt;
int ans(0);

const int p = 82595521;

void check(int pos)
{
	int i;
	for (int i = 0; i < lw; ++i)
	{
		if (w[i] != t[pos + i])
		{
			return;
		}
	}
	++ans;
}

int main()
{
	int ti, tn;
	cin >> tn;
	for (ti = 1; ti <= tn; ++ti)
	{
		scanf("%s%s", w, t);
		lw = strlen(w);
		lt = strlen(t);
		int ppw(0);
		int ppt(0);
		int ss(1);
		ans = 0;
		for (int i = 0; i < lw; ++i)
		{
			if (i > 0)
			{
				(ss *= 26) %= p;
			}
			((ppw *= 26) += w[i]) %= p;
			((ppt *= 26) += t[i]) %= p;
		}
		if (ppw == ppt) check(0);
		for (int i = lw; i < lt; ++i)
		{
			ppt -= ss * t[i - lw];
			while (ppt < 0) ppt += p;
			((ppt *= 26) += t[i]) %= p;
			if (ppw == ppt) check(i - lw + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
