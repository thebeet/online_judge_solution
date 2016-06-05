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

const int p = 65535;

void check(int pos)
{
	int i;
	//for (int i = 0; i < lw; ++i)
	{
		//if (w[i] != t[pos + i])
		if ((w[0] != t[pos + 0]) || (w[lw -1 ] != t[pos + lw -1]))
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
			(ss *= 26) %= p;
			((ppw *= 26) += w[i]) %= p;
			((ppt *= 26) += t[i]) %= p;
		}
		if (ppw == ppt) check(0);
		for (int i = lw; i < lt; ++i)
		{
			while (ppt < 0) ppt += p;
			((ppt *= 26) += t[i] - ss * t[i - lw]) %= p;
			if (ppt < 0) ppt += p;
			if (ppw == ppt) check(i - lw + 1);
		}
		cout << ans << endl;
	}
	return 0;
}
