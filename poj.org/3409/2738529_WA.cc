#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 10010;

struct point
{
	string x, y;
};
bool operator < (const point &p1, const point &p2)
{
	if (p1.x == p2.x)
	{
		return (p1.y < p2.y);
	}
	return (p1.x < p2.x);
}

// make pre-star graph
struct path
{
	int f, t;
}paths[100010];
int s[MAXN];
int ts[MAXN];
int p[MAXN];

bool operator < (const path &p1, const path &p2)
{
	return (p1.f < p2.f);
}

map<point, int> pid;

map<point, int> wid;

int frpid(0);

int gpid(const point &p1)
{
	int ret = pid[p1];
	if (ret == 0)
	{
		pid[p1] = ++frpid;
		ret = frpid;
	}
	return ret;
}

bool gone[10010];

int go(int pp)
{
	if (gone[pp])
	{
		return 0;
	}
	else
	{
		int i;
		int s(1);
		gone[pp] = true;
		for (i = p[pp]; i < p[pp + 1]; ++i)
		{
			s += go(paths[i].t);
		}
		return s;
	}
}

int main()
{
	int i, k;
	memset(paths, 0, sizeof(paths));
	memset(s, 0, sizeof(s));
	memset(ts, 0, sizeof(ts));
	memset(p, 0, sizeof(p));
	frpid = 0;
	scanf("%d", &k);
	for (i = 1; i <= k; ++i)
	{
		point p;
		cin >> p.x >> p.y;
		int pid1 = gpid(p);
		cin >> p.x >> p.y;
		int pid2 = gpid(p);
		paths[i].f = pid1;
		paths[i].t = pid2;
		paths[i + k].f = pid2;
		paths[i + k].t = pid1;
		++s[pid1];
		++s[pid2];
		point w;
		if (pid1 < pid2)
		{
			w.x = pid1;
			w.y = pid2;
		}
		else
		{
			w.x = pid2;
			w.y = pid1;
		}
		if (wid[w] == 0)
		{
			++ts[pid1];
			++ts[pid2];
			wid[w] = 1;
		}
	}
	sort(paths + 1, paths + 1 + k + k);
	p[1] = 1;
	for (i = 1; i <= k; ++i)
	{
		if ((s[i] & 1) == 1)
		{
			break;
		}
		p[i + 1] = p[i] + s[i];
	}
	if (i <= k)
	{
		cout << 0 << endl;
	}
	else
	{
		memset(gone, false, sizeof(gone));
		if (go(1) == k)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	
	return 0;
}




