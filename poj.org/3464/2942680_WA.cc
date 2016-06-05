#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

string num[100010];

struct cmp
{
	int f, t;
	int h;
	int tot;
	cmp(const int af = 0, const int at = 0, const int ah = 0, const int atot = 0) :
		f(af), t(at), h(ah), tot(atot)
	{
	}
	~cmp(){}
};

int solve(int n)
{
	int i;
	int mxtot(0);
	stack<cmp> st;
	st.push(cmp(0, n, 2, 0 ));
	while (st.empty() == false)
	{
		int hi = st.top().t;
		int h = st.top().h;
		int p = st.top().f;
		int tot = st.top().tot;
		st.pop();
		while ((num[p].c_str()[h] == '\0') && (p < hi))
		{
			++p;
		}
		while (p < hi)
		{
			for (i = p + 1; i < hi; ++i)
			{
				if (num[i].c_str()[h] != num[p].c_str()[h])
				{
					break;
				}
			}
			int r = i - p;
			if (r >= 1)
			{
				st.push(cmp(p, i, h + 1, tot + r));
			}
			p = i;
		}
		mxtot = max(mxtot, tot);
	}
	return mxtot;
}

int main()
{
	int i, n;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> num[i];
		bool flag = true;
		for (unsigned int j = num[i].size() - 1; j >= 3; --j)
		{
			if ((num[i][j] > '5') || ((num[i][j] == '5') && (flag)))
			{
				if (num[i][j] > '9')
				{
					//num[i][j] = '0';
				}
				++num[i][j - 1];
				flag = false;
			}
			else
			{
				flag = true;
			}
			if (num[i][j] == '0')
			{
				num[i][j] = '9' + 1;
			}
		}
//		cout << num[i] << endl;
	}
	sort(num, num + n);
	cout << solve(n) << endl;
	return 0;
}
/*
 * 
2
0.1295
0.130
*/
/*
4
0.250
0.2506
0.25115
0.2597
*/
