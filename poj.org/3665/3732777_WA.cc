/*
 * iCow.cpp
 *
 *  Created on: Jul 24, 2008
 *      Author: yonghu
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct icow
{
	int rat;
	int id;
};

bool operator < (const icow &ic1, const icow &ic2)
{
	if (ic1.rat == ic2.rat)
	{
		return ic1.id < ic2.id;
	}
	else
	{
		return ic1.rat > ic2.rat;
	}
}

icow ics[1024];

int main()
{
	int i, n, t;
	cin >> n >> t;
	for (i = 0; i < n; ++i)
	{
		cin >> ics[i].rat;
		ics[i].id = i + 1;
	}
	for (i = 0; i < t; ++i)
	{
		sort(ics, ics + n);
		cout << ics[0].id << endl;
		int p = ics[0].rat % (n - 1);
		int m = ics[0].rat / (n - 1);
		if (p >= ics[0].id) ++p;
		for (int j = 1; j < n; ++j)
		{
			ics[j].rat += m;
			if (ics[j].id <= p) ++ics[j].rat;
		}
	}
	return 0;
}
