/*
 * Occurrence_of_Digits.cpp
 *
 *  Created on: 2009-7-5
 *      Author: Administrator
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 128;

int dig[N][16];

void f(int a, int b)
{
	int tb(b);
	bool tmod[N];
	memset(tmod, false, sizeof(tmod));
	while ((tmod[a] == false) && (a != 0))
	{
		tmod[a] = true;
		++dig[tb][a * 10 / b];
		(a *= 10) %= b;
	}
}

int main()
{
	memset(dig, 0, sizeof(dig));
	for (int i = 2; i <= 100; ++i)
	{
		f(1, i);
	}
	int n, k;
	while (cin >> n >> k)
	{
		int sum(0);
		for (int j = 2; j <= n; ++j)
		{
			sum += dig[j][k];
		}
		cout << sum << endl;
	}
	return 0;
}
