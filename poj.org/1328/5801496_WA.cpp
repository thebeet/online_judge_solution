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

int main()
{
	int n, d;
	int ti(0);
	while ((cin >> n >> d), n > 0)
	{
		vector< pair<int, int> > islands(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> islands[i].first >> islands[i].second;
		}
		sort(islands.begin(), islands.end());
		bool flag(true);
		int sum(0);
		double pre;
		for (vector< pair<int, int> >::iterator it = islands.begin(); it != islands.end(); ++it)
		{
			if (it->second > d)
			{
				flag = false;
				break;
			}
			bool newradar(true);
			if (sum > 0)
			{
				if ((it->second * it->second + (it->first - pre) * (it->first - pre)) + 1e-8 < d * d)
				{
					newradar = false;
				}
			}
			if (newradar)
			{
				++sum;
				pre = it->first + sqrt((double)(d * d - it->second * it->second));
			}
		}
		cout << "Case " << ++ti << ": " << sum << endl;
	}
	return 0;
}
