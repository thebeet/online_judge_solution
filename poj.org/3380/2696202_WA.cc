#include <cstdio>
#include <algorithm>

using namespace std;

int n;

struct path
{
	int f, t;
	int l;
	int id;
	double st;
}ps[20010];
int p[10010];
int s[10010];

bool gone[10010];
int ic[10010];
int pc[10010];
int ec[10010];
int sc[10010];
int fc;

int queue[10010];

int nn;
struct shorttime
{
	int id;
	double t;
}sts[10010];

bool operator < (const path &p1, const path &p2)
{
	return (p1.f < p2.f);
}

bool operator < (const shorttime &p1, const shorttime &p2)
{
	return (p1.t > p2.t);
}

void maketree(int pp)
{
	int i;
	gone[pp] = true;
	pc[pp] = fc;
	for (i = p[pp]; i < p[pp + 1]; ++i)
	{
		if (gone[ps[i].t] == false)
		{
			ic[++fc] = i;
			queue[++queue[0]] = ps[i].t;
		}
	}
	ec[pp] = fc;
	
}

void bfs(int root = 1)
{
	int i;
	queue[0] = 1;
	queue[1] = root;
	memset(gone, false, sizeof(gone));
	fc = 0;
	for (i = 1; i <= queue[0]; ++i)
	{
		maketree(queue[i]);
	}
}

int dfs_sum(int p)
{
	int i;
	sc[p] = 1;
	for (i = pc[p] + 1; i <= ec[p]; ++i)
	{
		sc[p] += dfs_sum(ps[ic[i]].t);
	}
	return sc[p];
}

void dfs_ans(int p)
{
	int i;
	for (i = pc[p] + 1; i <= ec[p]; ++i)
	{
		double a = sc[ps[ic[i]].t];
		double b = n - a;
		sts[++nn].id = ps[ic[i]].id;
		sts[nn].t = a * b * ps[ic[i]].st;
		dfs_ans(ps[ic[i]].t);
	}
}

int main()
{
	int m, k, sh, sc;
	int i;
	scanf("%d%d%d%d", &n, &k, &sh, &sc);
	double shortspeed = (1.0 / (double)sh - 1.0 / (double)sc);
	m = n - 1;
	for (i = 1; i <= m; ++i)
	{
		scanf("%d%d%d", &ps[i].f, &ps[i].t, &ps[i].l);
		ps[i].st = (double)ps[i].l * shortspeed;
		ps[i].id = i;
		ps[i + m].f = ps[i].t;
		ps[i + m].t = ps[i].f;
		ps[i + m].l = ps[i].l;
		ps[i + m].id = i;
		++s[ps[i].f];
		++s[ps[i].t];
	}
	sort(ps + 1, ps + 1 + m + m);
	p[1] = 1;
	for (i = 1; i <= n; ++i)
	{
		p[i + 1] = p[i] + s[i];
	}
	
	bfs();
	dfs_sum(1);
	nn = 0;
	dfs_ans(1);
	sort(sts + 1, sts + m + 1);
	for (i = 1; i <= k; ++i)
	{
		printf("%d%c", sts[i].id, (i == k) ? '\n' : ' ');
	}
	return 0;
}
