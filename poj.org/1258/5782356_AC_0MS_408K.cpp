/*
 * Agri-Net.cpp
 *
 *  Created on: 2009-8-30
 *      Author: Administrator
 */

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int mat[128][128];
bool gone[128];

struct MST
{
	MST(const int d, const int t) :
		dis(d), toid(t)
	{
	}
	int dis;
	int toid;
};

bool operator < (const MST &p1, const MST &p2)
{
	return p1.dis > p2.dis;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		priority_queue<MST > q;
		memset(gone, false, sizeof(gone));
		while (q.empty() == false)
		{
			q.pop();
		}
		q.push(MST(0, 0));
		int sum(0);
		for (int i = 0; i < n; ++i)
		{
			while (gone[q.top().toid])
			{
				q.pop();
			}
			MST f = q.top();
			sum += f.dis;
			gone[f.toid] = true;
			for (int j = 0; j < n; ++j)
			{
				if (gone[j] == false)
				{
					q.push(MST(mat[f.toid][j], j));
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}
