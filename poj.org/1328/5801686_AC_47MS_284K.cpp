/*
 * Radar_Installation.cpp
 *
 *  Created on: Sep 2, 2009
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool cmp(const pair<double, double> &island1, const pair<double, double> &island2)
{
	return ((island1.second == island2.second) ? (island1.first < island2.first) : (island1.second < island2.second));
}

int main()
{
	int n, d;
	int ti(0);
	while ((cin >> n >> d), n > 0)
	{
		vector< pair<int, int> > islands(n);
		vector< pair<double, double> > rads;
		bool flag(true);
		if (d < 0) flag = false;
		for (int i = 0; i < n; ++i)
		{
			cin >> islands[i].first >> islands[i].second;
			if (islands[i].second > d)
			{
				flag = false;
			}
			else
			{
				double w = sqrt((double)(d * d - islands[i].second * islands[i].second + 1e-8));
				rads.push_back(make_pair(islands[i].first - w, islands[i].first + w));
			}
		}
		sort(rads.begin(), rads.end(), cmp);
		int sum(0);
		double pre;
		for (vector< pair<double, double> >::iterator it = rads.begin(); it != rads.end(); ++it)
		{
			if (sum == 0)
			{
				++sum;
				pre = it->second;
			}
			else
			{
				if (pre + 1e-8 < it->first)
				{
					++sum;
					pre = it->second;
				}
			}
		}
		if (flag == false) sum = -1;
		cout << "Case " << ++ti << ": " << sum << endl;
	}
	return 0;
}
