/*
 * Election_Time.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */

#include <iostream>
#include <algorithm>

using namespace std;

struct cow
{
	int a, b;
	int id;
	bool sel;
};

bool comp1(const cow &c1, const cow &c2)
{
	return c1.a > c2.a;
}

bool comp2(const cow &c1, const cow &c2)
{
	if (c2.sel == false)
	{
		return true;
	}
	if (c1.sel == false)
	{
		return false;
	}
	return c1.b > c2.b;

}

cow cs[65536];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &cs[i].a, &cs[i].b);
		cs[i].id = i + 1;
	}
	sort(cs, cs + n, comp1);
	for (int i = 0; i < k; ++i)
	{
		cs[i].sel = true;
	}
	sort(cs, cs + n, comp2);
	cout << cs[0].id << endl;
	return 0;
}
