/*
 * Quad_Trees.cpp
 *
 *  Created on: 2009-9-1
 *      Author: thebeet
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int mat[512][512];

vector<int> ans;

void output(queue< pair< pair<int, int>, int> > &q, const int x, const int y, const int h)
{
	bool flag(false);
	int tx(x + (1 << h));
	for (int i = x; i < tx; ++i)
	{
		int ty(y + (1 << h));
		for (int j = y; j < ty; ++j)
		{
			if (mat[i][j] != mat[x][y])
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (flag)
	{
		ans.push_back(1);
		q.push(make_pair(make_pair(x, y), h - 1));
		q.push(make_pair(make_pair(x, y + (1 << (h - 1))), h - 1));
		q.push(make_pair(make_pair(x + (1 << (h - 1)), y), h - 1));
		q.push(make_pair(make_pair(x + (1 << (h - 1)), y + (1 << (h - 1))), h - 1));
	}
	else
	{
		ans.push_back(0);
		ans.push_back(mat[x][y]);
	}
}

void bfs(const int h)
{
	queue< pair< pair<int, int>, int> > q;
	q.push(make_pair(make_pair(0, 0), h));
	while (q.empty() == false)
	{
		pair< pair<int, int>, int> now(q.front());
		q.pop();
		output(q, now.first.first, now.first.second, now.second);
	}
}

int main()
{
	int tn;
	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ++ti)
	{
		int n, hn(0);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &mat[i][j]);
			}
		}
		while (n > 0)
		{
			++hn;
			n >>= 1;
		}
		ans.clear();
		bfs(hn - 1);
		int t(0);
		for (int i = 0; i < (ans.size() % 4); ++i)
		{
			(t <<= 1) |= ans[i];
		}
		if (t > 9)
		{
			printf("%c", 'a' + t - 10);
		}
		else
		{
			printf("%d", t);
		}
		for (int i = ans.size() % 4; i < ans.size(); i += 4)
		{
			int t(0);
			for (int j = i; (j < i + 4) && (j < ans.size()); ++j)
			{
				(t <<= 1) |= ans[j];
			}
			if (t > 9)
			{
				printf("%c", 'a' + t - 10);
			}
			else
			{
				printf("%d", t);
			}
		}
		printf("\n");
	}
	return 0;
}
