#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int length[10010];
int n, k;

vector< vector < pair<int, int> > > graph;

void expend(queue<int> &q, bool gone[1024], int p, int lenfree)
{
	gone[p] = true;
	q.push(p);
	for (int i = 0; i < graph[p].size(); ++i)
	{
		if ((graph[p][i].second <= lenfree) && (gone[graph[p][i].first] == false))
		{
			expend(q, gone, graph[p][i].first, lenfree);
		}
	}
}

void expendfree(queue<int> &q, bool gone[1024], int p, int lenfree)
{
	for (int i = 0; i < graph[p].size(); ++i)
	{
		if (gone[graph[p][i].first] == false)
		{
			expend(q, gone, graph[p][i].first, lenfree);
		}
	}
}

bool bfs(const int lenfree)
{
	bool gone[1024];
	memset(gone, false, sizeof(gone));
	queue<int> q[2];
	int p0(0), p1(1);
	expend(q[p0], gone, 1, lenfree);
	int ans(0);
	while (gone[n] == false)
	{
		if (ans == k)
		{
			break;
		}
		if (q[p0].empty())
		{
			break;
		}
		while (q[p0].empty() == false)
		{
			expendfree(q[p1], gone, q[p0].front(), lenfree);
			q[p0].pop();
		}
		swap(p0, p1);
		++ans;
	}
	return gone[n];
}

int main()
{
	int i, j, p;
	cin >> n >> p >> k;
	graph.resize(n + 1);
	for (i = 1; i <= p; ++i)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &length[i]);
		graph[a].push_back(make_pair(b, length[i]));
		graph[b].push_back(make_pair(a, length[i]));
	}
	length[0] = 0;
	length[p + 1] = 100000000;
	sort(length + 1, length + p + 1);
	int lo = 0;
	int hi = p + 1;
	if (bfs(100000000) == false)
	{
		cout << "-1" << endl;
		return 0;
	}
	if (bfs(0) == true)
	{
		cout << "0" << endl;
		return 0;
	}
	while (lo + 1 < hi)
	{
		int mid((lo + hi) / 2);
		(bfs(length[mid]) ? hi : lo) = mid;
	}
	cout << length[hi] << endl;
	return 0;
}
