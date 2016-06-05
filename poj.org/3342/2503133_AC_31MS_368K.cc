#include <iostream>
#include <string>

using namespace std;

#define MAXN 210

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int total;
string names[MAXN];
// make pre-star graph
struct path
{
	int f, t;
}paths[MAXN];
int s[MAXN];
int p[MAXN];
int ans[2][MAXN];

void findans(int t)
{
	int i;
	ans[1][t] = 1;
	for (i = p[t]; i < p[t + 1]; ++i)
	{
		findans(paths[i].t);
		ans[1][t] += ans[0][paths[i].t];
		ans[0][t] += MAX(ans[1][paths[i].t], ans[0][paths[i].t]);
	}
}

bool checkunique(int t, bool use)
{
	int i;
	if (use)
	{
		if (ans[0][t] == ans[1][t])
		{
			return false;
		}
		for (i = p[t]; i < p[t + 1]; ++i)
		{
			if (checkunique(paths[i].t, false) == false)
			{
				return false;
			}
		}
	}
	else
	{
		for (i = p[t]; i < p[t + 1]; ++i)
		{
			if (ans[1][paths[i].t] >= ans[0][paths[i].t])
			{ 
				if (checkunique(paths[i].t, true) == false)
				{
					return false;
				}
			}
		}
	}		
	return true;
}

int findname(string name)
{
	int i;
	for (i = 1; i <= total; ++i)
	{
		if (name == names[i])
		{
			return i;
		}
	}
	names[++total] = name;
	return total;
}

bool cmp(path p1, path p2)
{
	return (p1.f < p2.f);
}

int main()
{
	int n;
	while ((cin >> n), n > 0)
	{
		int i;
		string name;
		
		total = 1;
		cin >> name;
		names[1] = name;
		memset(paths, 0, sizeof(paths));
		memset(s, 0, sizeof(s));
		memset(p, 0, sizeof(p));
		
		for (i = 2; i <= n; ++i)
		{
			cin >> name;
			paths[i - 1].t = findname(name);
			cin >> name;
			paths[i - 1].f = findname(name);
			++s[paths[i - 1].f];
		}
		sort(paths + 1, paths + n, cmp);
		p[1] = 1;
		for (i = 1; i <= n; ++i)
		{
			p[i + 1] = p[i] + s[i];
		}
		
		memset(ans, 0, sizeof(ans));
		findans(1); 
		cout << MAX(ans[0][1], ans[1][1]) << " ";
		
		if (checkunique(1, (ans[1][1] >= ans[0][1])))
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}
