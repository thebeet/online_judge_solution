/*
 * A_hard_Aoshu_Problem.cpp
 *
 *  Created on: 2011-11-15
 *      Author: acer
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
string s1, s2, s3;
map<char, int> mp;
vector<bool> used(10, false);
string sss;

int d(const string &s)
{
	int ans(0);
	for (int i = s.size() - 1; i >= 0; --i)
	{
		(ans *= 10) += mp[s[i]];
	}
	return ans;
}

int s(int pp)
{
	if (sss[pp] == 'F')
	{
		if ((s1.size() > 1) && (mp[s1[0]] == 0)) return 0;
		if ((s2.size() > 1) && (mp[s2[0]] == 0)) return 0;
		if ((s3.size() > 1) && (mp[s3[0]] == 0)) return 0;
		long long d1 = d(s1);
		long long d2 = d(s2);
		long long d3 = d(s3);
		int ans(0);
		if (d1 + d2 == d3) ++ans;
		if (d1 - d2 == d3) ++ans;
		if (d1 * d2 == d3) ++ans;
		if ((d2 != 0) && (d1 == d3 * d2)) ++ans;
		return ans;
	}
	else
	{
		int ans(0);
		for (int i = 0; i <= 9; ++i)
		{
			if (used[i] == false)
			{
				mp[sss[pp]] = i;
				used[i] = true;
				ans += s(pp + 1);
				used[i] = false;
			}
		}
		return ans;
	}
}

int main()
{
	int tn;
	cin >> tn;
	for (int i = 0; i < tn; ++i)
	{
		used.clear();
		used.resize(10, false);
		cin >> s1 >> s2 >> s3;
		sss = "";
		char cc[256];
		memset(cc, 0, sizeof(cc));
		for (int i = 0; i < s1.size(); ++i)
		{
			++cc[s1[i]];
		}
		for (int i = 0; i < s2.size(); ++i)
		{
			++cc[s2[i]];
		}
		for (int i = 0; i < s3.size(); ++i)
		{
			++cc[s3[i]];
		}
		for (char c = 'A'; c <= 'E'; ++c)
		{
			if (cc[c] > 0)
			{
				sss += c;
			}
		}
		sss += 'F';
		cout << s(0) << endl;
	}
	return 0;
}
