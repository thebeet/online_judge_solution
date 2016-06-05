#include <iostream>
#include <algorithm>

using namespace std;

struct path
{
	int f, t;
	int leng;
};

bool operator < (const path &p1, const path &p2)
{
	return (p1.leng < p2.leng);
}

path ps[15010];

int father[1024];



int tfind(const int x)
{
	if (father[x] != x)
	{
		father[x] = tfind(father[x]);
	}
	return father[x];
}

int anss[1024];

int main()
{
	int i, n, m;
	cin >> n >> m;
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &ps[i].f, &ps[i].t, &ps[i].leng);
	}
	sort(ps, ps + m);
	for (i = 1; i <= n; ++i)
	{
		father[i] = i;
	}
	int ans(0);
	for (i = 0; i < m; ++i)
	{
		int f1 = tfind(ps[i].f);
		int f2 = tfind(ps[i].t);
		if (f1 != f2)
		{
			ans = ps[i].leng;
			father[f1] = tfind(f2);
			anss[++anss[0]] = i;
		}
	}
	cout << ans << endl;
	cout << n - 1 << endl;
	for (i = 1; i <= anss[0]; ++i)
	{
		cout << ps[anss[i]].f << " " << ps[anss[i]].t << endl;
	}
	return 0;
}
