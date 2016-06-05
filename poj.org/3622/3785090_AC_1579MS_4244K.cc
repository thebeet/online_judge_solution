#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

pair<int, int> cows[100010];
pair<int, int> grass[100010];

map<int, int> avl;

bool comp (const pair<int, int> &p1, const pair<int, int> &p2)
{
	return (p1.second > p2.second);
}

int main()
{
	int i, n, m;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; ++i)
	{
		scanf("%d%d", &cows[i].first, &cows[i].second);
	}
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d", &grass[i].first, &grass[i].second);
	}
	sort(cows, cows + n, comp);
	sort(grass, grass + m, comp);
	grass[m].second = -1;
	int p(0);
	long long cost(0);
	for (i = 0; i < n; ++i)
	{
		while (grass[p].second >= cows[i].second)
		{
			++avl[grass[p++].first];
		}
		avl[cows[i].first];
		map<int, int>::iterator pos = avl.find(cows[i].first);
		if (pos->second > 0)
		{
			cost += (long long)(pos->first);
			if (--(pos->second) == 0)
			{
				avl.erase(pos);
			}
		}
		else
		{
			map<int, int>::iterator opos(pos);
			if (++pos == avl.end())
			{
				cout << "-1" << endl;
				return 0;
			}
			else
			{
				cost += (long long)(pos->first);
				if (--(pos->second) == 0)
				{
					avl.erase(pos);
				}
			}
			avl.erase(opos);
		}
	}
	cout << cost << endl;
	return 0;
}
