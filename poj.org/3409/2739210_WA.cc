#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int MAXN = 40010;

struct point
{
	int x, y;
};

struct ww
{
	int x, y;
};

bool operator < (const ww &p1, const ww &p2)
{
	if (p1.x == p2.x)
	{
		return (p1.y < p2.y);
	}
	return (p1.x < p2.x);
}

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
}paths[MAXN];
int s[MAXN];
int ts[MAXN];
int p[MAXN];

bool operator < (const path &p1, const path &p2)
{
	return (p1.f < p2.f);
}

map<point, int> pid;

map<ww, int> wid;

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

bool gone[MAXN];

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
	scanf("%*d");
	memset(paths, 1, sizeof(paths));
	point pt1, pt2;
	k = 0;
	while (cin >> pt1.x >> pt1.y >> pt2.x >> pt2.y)
	{
		++k;
		int pid1 = gpid(pt1);
		int pid2 = gpid(pt2);
		paths[(k << 1) - 1].f = pid1;
		paths[(k << 1) - 1].t = pid2;
		paths[(k << 1)].f = pid2;
		paths[(k << 1)].t = pid1;
		++s[pid1];
		++s[pid2];
		ww w;
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
	for (i = 1; i <= frpid; ++i)
	{
		if ((ts[i] & 1) == 1)
		{
			break;
		}
		p[i + 1] = p[i] + s[i];
	}
	if (i <= frpid)
	{
		cout << 0 << endl;
	}
	else
	{
		memset(gone, false, sizeof(gone));
		if (go(1) == frpid)
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
